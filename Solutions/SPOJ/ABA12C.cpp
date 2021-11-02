#include <bits/stdc++.h>

using namespace std;

//#define pi 3.141592653589793
#define eulerconstant 0.577215664901532
#define MAX_N 105
#define LG_N 17
#define f first
#define s second
#define inf ~(1<<31)
#define inf64 1000000000000000000
#define goldenratio ((double)(1 + sqrt(5)) / 2)
#define isvalid(a_, b_, n_, m_) (a_ >= 0 && a_ < n_ && b_ >= 0 && b_ < m_)
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define forr(i, l, r) for (int i = (int)(l); i < (int)(r); ++i)
#define Mid ((l + r) >> 1)
#define filIn freopen("input.txt", "r", (__acrt_iob_func(0)));
#define filOut freopen("output.txt", "w", (__acrt_iob_func(1)));

typedef pair<int, int> ii;
typedef pair<int, pair<int, int>> iii;
typedef pair<char, int> ci;
typedef pair<string, int> si;
typedef pair<int, string> is;
typedef vector< int > vi;
typedef vector< long > vl;
typedef vector< char > vc;
typedef vector<pair<int, int>> vii;
typedef vector<pair< int, pair<int, int>>> viii;
typedef vector<vector<int>> vvi;
typedef long long ll;
typedef vii no;
struct aresta
{
	int a, b, p;
};
bool Comp(aresta a, aresta b) { return a.p < b.p; }

ll Knapsack(int N, vi& Pesos, vi& Valor)
{
	ll dp[MAX_N];
	dp[0] = 0;
	for (int i = 1; i <= N; ++i)
		dp[i] = inf;
	for (int k = 0; k < N; ++k)
	{
		if (Valor[k] == -1) continue;
		for (int d = k + 1; d <= N; ++d)
		{
			dp[d] = min(dp[d], dp[d - Pesos[k]] + Valor[k]);
		}
	}

	return dp[N];
}

int main()
{
	int N, W, t;
	cin >> t;
	while (t--)
	{
		int k = 0;
		scanf("%d %d", &W, &N);
		vi Pesos(N), Valor(N);
		for (int i = 0; i < N; ++i)
		{
			scanf("%d", &Valor[i]);
			Pesos[i] = i + 1;
		}

		ll Ans = Knapsack(N, Pesos, Valor);
		printf("%lld\n", Ans == inf ? -1 : Ans);
	}
	return 0;
}