#include <bits/stdc++.h>

using namespace std;

//#define pi 3.141592653589793
#define eulerconstant 0.577215664901532
#define MAX_N 200005
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
//typedef iii no;

struct no
{
	int sum, pre, suf, ans;
};

int N, Vet[int(MAX_N/4 + 1)];
no Seg[MAX_N];

no Modify(no a, no b)
{
	no Ans;
	Ans.sum = a.sum + b.sum;
	Ans.pre = max(a.pre, a.sum + b.pre);
	Ans.suf = max(b.suf, b.sum + a.suf);
	Ans.ans = max(max(a.ans, b.ans), a.suf + b.pre);
	return Ans;
}

no make_node(int val)
{
	no Ans;
	Ans.sum = val;
	Ans.pre = Ans.suf = Ans.ans = max(-100000, val);
	return Ans;
}

no build(int id = 1, int l = 0, int r = N - 1)
{
	if (r == l)	return Seg[id] = make_node(Vet[l]);
	return Seg[id] = Modify(build(2 * id, l, Mid), build(2 * id + 1, Mid + 1, r));
}

no query(int i, int j, int id = 1, int l = 0, int r = N - 1)
{
	if (i == l && r == j)	return Seg[id];
	if (j <= Mid)
		return query(i, j, 2 * id, l, Mid);
	if (i > Mid)
		return query(i, j, 2 * id + 1, Mid + 1, r);
	return Modify(query(i, Mid, 2 * id, l, Mid), query(Mid + 1, j, 2 * id + 1, Mid + 1, r));
}

no upd(int i, int x, int id = 1, int l = 0, int r = N - 1)
{
	if (r < i || i < l) return Seg[id];
	if (r == l)	return Seg[id] = make_node(x);
	return Seg[id] = Modify(upd(i, x, 2 * id, l, Mid), upd(i, x, 2 * id + 1, Mid + 1, r));
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
		int Op, L, R; scanf("%d %d %d", &Op, &L, &R);
		if (!Op)
		{
			upd(L-1, R);
		}
		else
		{
			if (L > R)
				swap(L, R);
			L--; R--;
			no Ans = query(L, R);
			printf("%d\n", Ans.ans);
		}
	}

	return 0;
}