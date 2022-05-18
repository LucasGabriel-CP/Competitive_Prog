#include <bits/stdc++.h>

using namespace std;

#define pi 3.141592653589793
#define eulerconstant 0.577215664901532
#define MAXN 1005
#define LGN 17
#define LSOne(S) ((int)(S) & -(int)(S))
#define f first
#define s second
#define inf (int)1e9
#define inf64 (int)4e18
#define goldenratio ((double)(1 + sqrt(5)) / 2)
#define isvalid(a_, b_, n_, m_) (a_ >= 0 && a_ < n_ && b_ >= 0 && b_ < m_)
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define rforn(i, n) for (int i = (int)(n); i >= 0; --i)
#define forr(i, l, r) for (int i = (int)(l); i < (int)(r); ++i)
#define rforr(i, l, r) for (int i = (int)(l); i >= (int)(r); --i)
#define Mid (l + ((r - l) >> 1))
#define GCD(a_, b_) (__gcd(a_, b_))
#define LCM(a_, b_) (a_/__gcd(a_, b_)*b_)
#define filIn freopen("input.txt", "r", stdin);
#define filOut freopen("output.txt", "w", stdout);

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
typedef int no;

vii AdjList[MAXN];
int n;

bool BellMan(){
	vi Dist(n, inf); Dist[0] = 0;
	for (int i = 0; i < n - 1; ++i){
		bool modified = false;
		for (int j = 0; j < n; ++j){
			if (Dist[j] == inf) continue;
			for (auto to : AdjList[j]){
				int v = to.f, w = to.s;
				if (Dist[v] > Dist[j] + w){
					Dist[v] = Dist[j] + w;
					modified = true;
				}
			}
		}
		if (!modified) break;
	}

	for (int u = 0; u < n; ++u){
		if (Dist[u] == inf) continue;
		for (auto to : AdjList[u]){
			int v = to.f, w = to.s;
			if (Dist[v] > Dist[u] + w){
				return true;
			}
		}
	}
	return false;
}

void solve(){
	forn(i, MAXN) AdjList[i].clear();
	int m;
	cin >> n >> m;
	int a, b, p;
	forn(i, m){
		cin >> a >> b >> p;
		AdjList[a].push_back({b, p});
	}
	cout << (BellMan() ? "possible\n" : "not possible\n");
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while(t--)
		solve();

    return 0;
}
