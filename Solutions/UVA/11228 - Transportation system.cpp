#include <bits/stdc++.h>

using namespace std;

#define pi 3.141592653589793
#define eulerconstant 0.577215664901532
#define MAXN 1050
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
typedef long long ll;
typedef int no;

int n, r, ans;
ii Points[MAXN];
double Matrix[MAXN][MAXN], Roads, Rail;

void prim(){
    vector<bool> vis(n, false);
    vector<pair<double, int>> min_e(n, {(double)inf, -1});
    min_e[0].f = Roads = Rail = 0.0;
    ans = 0;
    forn(i, n){
        int v = -1;
        forn(j, n){
            if (!vis[j] && (v == -1 || min_e[j].f < min_e[v].f))
                v = j;
        }
        vis[v] = true;
        if (min_e[v].f > r){
            ++ans; Rail += min_e[v].f;
        }
        else Rail += min_e[v].f;
        forn(j, n){
            if (Matrix[v][j] < min_e[j].f)
            min_e[j] = {Matrix[v][j], v};
        }
    }
}

void solve(){
    cin >> n >> r;
    forn(i, n){
        int x, y; cin >> x >> y;
        Points[i] = {x, y};
    }
    forn(i, n){
        Matrix[i][i] = inf;
        forr(j, i + 1, n){
            double w = sqrt((double)(Points[i].f - Points[j].f)*(Points[i].f - Points[j].f) + (double)(Points[i].s - Points[j].s)*(Points[i].s - Points[j].s));
            Matrix[i][j] = w;
            Matrix[j][i] = w;
        }
    }
    prim();
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//filIn;	//filOut;
    int c; cin >> c;
    forn(i, c){
        solve();
        cout << "Case #" << i + 1 << ' ' << ans << ' ' << round(Roads) << ' ' << round(Rail) << '\n';
    }

	return 0;
}
