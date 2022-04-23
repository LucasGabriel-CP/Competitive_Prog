#include <bits/stdc++.h>

using namespace std;

#define pi 3.141592653589793
#define eulerconstant 0.577215664901532
#define MAXN 1005
#define LGN 17
#define LSOne(S) ((int)(S) & -(int)(S))
#define f first
#define s second
#define inf 1e9
#define inf64 4e18
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

int p, u, r, RV[10], dist[19000];
bool Vis[19000];

int bfs(int o, int d){
    queue<int> myQ;
    memset(Vis, 0, 19000);
    dist[o] = 0;
    myQ.push(o);
    Vis[o] = true;
    while(!myQ.empty()){
        int v = myQ.front();
        myQ.pop();
        forn(i, r){
            int u = v + RV[i];
            if (u > 9999) u -= 10000;
            if (!Vis[u]){
                if (u == d) return dist[v] + 1;
                dist[u] = dist[v] + 1;
                myQ.push(u);
                Vis[u] = true;
            }
        }
    }
    return o == d ? 0 : -1;
}

void solve(){
    int c = 1;
    while (cin >> p >> u >> r, p || u || r){
        forn(i, r)
            cin >> RV[i];
        int ans = bfs(p, u);
        cout << "Case " << c++ << ": ";
        if (ans == -1) cout << "Permanently Locked\n";
        else cout << ans << '\n';
    }
}

int main(){
    //filIn; //filOut;
    ios_base::sync_with_stdio(false); cin.tie(0);
    solve();

    return 0;
}
