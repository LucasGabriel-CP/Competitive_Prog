#include <bits/stdc++.h>

using namespace std;

//#define pi 3.141592653589793
#define eulerconstant 0.577215664901532
#define MAX_N 100005
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
typedef ii no;
struct aresta
{
	int a, b, p;
};
bool Comp(aresta a, aresta b) { return a.p < b.p; }

vvi Visit;
int x[] = { 2, 2, 1, -1, -2, -2, 1, -1 };
int y[] = { -1, 1, 2, 2, 1, -1, -2, -2 };

void solve(ii O, ii D)
{
	queue< ii > myQ;
	Visit.assign(70, vi(70, inf));

	myQ.push(O);
	Visit[O.f][O.s] = 0;
	ii v = O;
	while (!myQ.empty())
	{
		v = myQ.front();
		myQ.pop();
		forn(i, 8)
		{
			if (isvalid(v.f + x[i], v.s + y[i], 8, 8))
			{
				if (Visit[v.f + x[i]][v.s + y[i]] > Visit[v.f][v.s] + 1)
				{
					Visit[v.f + x[i]][v.s + y[i]] = Visit[v.f][v.s] + 1;
					myQ.push({ v.f + x[i], v.s + y[i] });
				}
			}
		}
		if ((v.f == D.f && v.s == D.s)) break;
	}

	printf("%d\n", Visit[D.f][D.s]);
}

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		char N[3], M[3]; scanf(" %s %s", N, M);
		solve({ N[1] - '1', N[0] - 'a' }, { M[1] - '1', M[0] - 'a' });
	}

	return 0;
}