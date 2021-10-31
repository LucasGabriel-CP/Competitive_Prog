#include <bits/stdc++.h>

using namespace std;

#define MAX_N 505
#define f first
#define s second
#define inf ~(1<<31)
#define isvalid(a_, b_, n_, m_) (a_ >= 0 && a_ < n_ && b_ >= 0 && b_ < m_)
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define forr(i, l, r) for (int i = (int)(l); i < (int)(r); ++i)

typedef pair<int, int> ii;
typedef pair<int, pair<int, int>> iii;
typedef vector< int > vi;
typedef vector<pair< int, pair<int, int>>> viii;
typedef vector<vector<int>> vvi;

char Matrix[MAX_N][MAX_N];
int x[] = { 1, 0, -1, 0 };
int y[] = { 0, 1, 0, -1 };

int main()
{
	int N, M; scanf("%d %d", &N, &M);
	ii O, D;
	forn(i, N)
	{
		forn(j, M)
		{
			scanf(" %c", &Matrix[i][j]);
			if (Matrix[i][j] == 'H')
				O = { i, j };
			else if (Matrix[i][j] == 'E')
			{
				D = { i, j }; Matrix[i][j] = '0';
			}
			else if (Matrix[i][j] == '.')
				Matrix[i][j] = '0';
		}
	}

	priority_queue<iii, viii, greater<iii>> myPq;
	vvi Dist(N, vi(M, inf));
	Dist[O.f][O.s] = 0;
	myPq.push({ 0, {O.f, O.s} });
	while (!myPq.empty())
	{
		int d = myPq.top().f, i = myPq.top().s.f, j = myPq.top().s.s;
		myPq.pop();
		if (d != Dist[i][j]) continue;
		forn(e, 4)
		{
			int ei = i + x[e], ej = j + y[e];
			if (!isvalid(ei, ej, N, M) 
				|| Matrix[ei][ej] == '#') continue;
			if (Dist[i][j] + int(Matrix[ei][ej] - '0') < Dist[ei][ej])
			{
				Dist[ei][ej] = Dist[i][j] + int(Matrix[ei][ej] - '0');
				myPq.push({ Dist[ei][ej], {ei, ej} });
			}
		}
	}

	Dist[D.f][D.s] == inf ? printf("ARTSKJID\n") : printf("%d\n", Dist[D.f][D.s]);

	return 0;
}