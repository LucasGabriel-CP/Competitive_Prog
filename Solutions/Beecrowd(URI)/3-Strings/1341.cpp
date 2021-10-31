#include <bits/stdc++.h>

using namespace std;

#define MAX_N 120005 
#define f first
#define s second
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define forr(i, l, r) for (int i = (int)(l); i < (int)(r); ++i)

typedef pair<int, int> ii;
typedef vector< int > vi;
typedef vector<vector<int>> vvi;

char Matrix[25][25], moves[2][550];
ii Cria[3];
int Num[2];

void LCS(string Str1, string Str2, int Case)
{
	int N = (int)Str1.size();
	int M = (int)Str2.size();
	vvi dp(2, vi(M + 1));
	bool bi;

	for (int i = 0; i <= N; i++)
	{
		bi = i & 1;
		for (int j = 0; j <= M; j++)
		{
			if (!i || !j)
				dp[bi][j] = 0;
			else
				if (Str1[i - 1] == Str2[j - 1])
					dp[bi][j] = dp[1 - bi][j - 1] + 1;
				else
					dp[bi][j] = max(dp[1 - bi][j], dp[bi][j - 1]);
		}
	}

	printf("Case %d: %d %d\n", Case, N - dp[bi][M], M - dp[bi][M]);
}

void solve(int Case)
{
	string Caminho[2];
	forn(i, 2)
	{
		Caminho[i] = Matrix[Cria[i].f][Cria[i].s];
		forn(k, Num[i])
		{
			switch (moves[i][k])
			{
			case 'N':
				Cria[i].f--;	break;
			case 'S':
				Cria[i].f++;	break;
			case 'E':
				Cria[i].s++;	break;
			case 'L':
				Cria[i].s--;	break;
			default:
				break;
			}
			Caminho[i].push_back(Matrix[Cria[i].f][Cria[i].s]);
		}
	}
	LCS(Caminho[0], Caminho[1], Case);
}

int main()
{
	int t; scanf("%d", &t);
	forn(c, t)
	{
		int h, w; scanf("%d %d", &h, &w);
		forn(i, h)
		{
			forn(j, w)
			{
				scanf(" %c", &Matrix[i][j]);
			}
		}
		forn(i, 2)
		{
			int a, b; scanf("%d %d %d", &Num[i], &a, &b);
			Cria[i] = { a - 1, b - 1 };
			forn(j, Num[i])
			{
				scanf(" %c", &moves[i][j]);
			}
		}
		solve(c + 1);
	}

	return 0;
}