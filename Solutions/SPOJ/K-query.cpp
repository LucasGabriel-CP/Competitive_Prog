#include <bits/stdc++.h>

using namespace std;

//#define pi 3.141592653589793
#define eulerconstant 0.577215664901532
#define MAX_N 120005 
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
typedef vi no;
struct aresta
{
	int a, b, p;
};
bool Comp(aresta a, aresta b) { return a.p < b.p; }

int N, Vet[MAX_N];
no Seg[MAX_N];

void build(int id = 1, int l = 0, int r = N)
{
	if (r - l < 2)
	{
		Seg[id].push_back(Vet[l]);
		return;
	}
	build(2 * id, l, Mid);
	build(2 * id + 1, Mid, r);
	merge(Seg[2 * id].begin(), Seg[2 * id].end(), Seg[2 * id + 1].begin(), Seg[2 * id + 1].end(), back_inserter(Seg[id]));
}

int query(int i, int j, int k, int id = 1, int l = 0, int r = N)
{
	if (i >= r || l >= j)
		return 0;
	if (i <= l && r <= j)
		return Seg[id].size() - (upper_bound(Seg[id].begin(), Seg[id].end(), k) - Seg[id].begin());
	return query(i, j, k, 2 * id, l, Mid) + query(i, j, k, 2 * id + 1, Mid, r);
}

int main()
{
	scanf("%d", &N);
	forn(i, N)
		scanf("%d", &Vet[i]);
	build();
	int q; scanf("%d", &q);
	while (q--)
	{
		int L, R, K; scanf("%d %d %d", &L, &R, &K);
		if (L > R)
			swap(L, R);
		L--;
		printf("%d\n", query(L, R, K));
	}

	return 0;
}