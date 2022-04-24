#include <bits/stdc++.h>

using namespace std;

#define pi 3.141592653589793
#define eulerconstant 0.577215664901532
#define MAXN 100005
#define LGN 15
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
typedef unsigned long long ll;
typedef int no;

int n, dp[4*MAXN], coin[MAXN];

ii cc(int val){
    dp[0] = 0;
    for (int c = 1; c < 3*MAXN; ++c){
		auto& d = dp[c] = inf;
		for (int i = 0; i < n; ++i)
			if (c >= coin[i])
				d = min(d, dp[c - coin[i]] + 1);
	}
    forr(i, val, 4*MAXN)
        if (dp[i] != inf)
            return {dp[i], i};
}

void solve(){
    int val;
    cin >> val >> n;
    forn(i, n) cin >> coin[i];
    ii ans = cc(val);
    cout << ans.s << ' ' << ans.f << '\n';
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	filIn; filOut;
	int Case; cin >> Case;
	forn(c, Case){
	    solve();
	}

	return 0;
}
