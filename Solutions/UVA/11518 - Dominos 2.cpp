#include <bits/stdc++.h>

using namespace std;

#define pi 3.141592653589793
#define eps 0.000005
#define eulerconstant 0.577215664901532
#define MAXN 10005
#define LGN 17
#define LSOne(S) ((int)(S) & -(int)(S))
#define f first
#define s second
#define inf ~(1<<31)
#define inf64 1000000000000000000
#define goldenratio ((double)(1 + sqrt(5)) / 2)
#define isvalid(a_, b_, n_, m_) (a_ >= 0 && a_ < n_ && b_ >= 0 && b_ < m_)
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define rforn(i, n) for (int i = (int)(n); i >= 0; --i)
#define forr(i, l, r) for (int i = (int)(l); i < (int)(r); ++i)
#define rforr(i, l, r) for (int i = (int)(l); i >= (int)(r); --i)
#define Mid (l + ((r - l) >> 1))
#define filIn freopen("input.txt", "r", stdin);
#define filOut freopen("output.txt", "w", stdout);

typedef pair<long long, long long> ii;
typedef pair<double, double> dd;
typedef pair<int, pair<int, int>> iii;
typedef pair<char, int> ci;
typedef pair<string, int> si;
typedef pair<int, string> is;
typedef vector< int > vi;
typedef vector< long long > vll;
typedef vector< char > vc;
typedef vector<pair<int, int>> vii;
typedef vector<pair< int, pair<int, int>>> viii;
typedef vector<vector<int>> vvi;
typedef long long ll;
typedef unsigned long long ull;
typedef int no;

vvi ListAdj;
bool Vis[MAXN];
int ans;

void dfs(int v){
    Vis[v] = true;
    ++ans;
    for(int i : ListAdj[v])
        if (!Vis[i]){
            dfs(i);
        }
}

void solve(){
    int t; cin >> t;
    int n, m, l, v, e;
    while(t--){
        cin >> n >> m >> l;
        ListAdj.assign(n, vi());
        memset(Vis, 0, n);
        forn(i, m){
            cin >> v >> e;
            --v; --e;
            ListAdj[v].push_back(e);
        }
        ans = 0;
        forn(i, l){
            cin >> v;
            if (!Vis[v-1]){
                dfs(v-1);
            }
        }
        cout << ans << '\n';
    }
}

int main(){
    //filIn; //filOut;
    ios_base::sync_with_stdio(false); cin.tie(0);
    solve();

    return 0;
}
