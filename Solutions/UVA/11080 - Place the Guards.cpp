#include <bits/stdc++.h>

using namespace std;

#define pi 3.141592653589793
#define eulerconstant 0.577215664901532
#define MAXN 6050
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

int n, m, ans;
vi AdjList[MAXN];

int check(){
    vector<int> side(n, -1);
    bool ok = true;
    queue<int> q;
    int ans = 0;
    for (int i = 0; i < n; ++i){
        if (side[i] == -1){
            int qnt[2] = {0, 0};
            q.push(i);
            side[i] = 0;
            qnt[side[i]]++;
            while(!q.empty()){
                int v = q.front();
                q.pop();
                for (int u : AdjList[v]){
                    if (side[u] == -1){
                        side[u] = side[v] ^ 1;
                        qnt[side[u]]++;
                        q.push(u);
                    }
                    else ok &= side[u] != side[v];
                }
            }
            if (!qnt[0] || !qnt[1]) ++ans;
            else ans += min(qnt[0], qnt[1]);
        }
    }
    if (!ok) return -1;
    return ans;
}

void solve(){
    int t; cin >> t;
    while(t--){
        cin >> n >> m;
        forn(i, n){
            AdjList[i].clear();
        }
        forn(i, m){
            int u, v; cin >> u >> v;
            AdjList[u].push_back(v);
            AdjList[v].push_back(u);
        }
        cout << check() << '\n';
    }

}

int main(){
    filIn; filOut;
    ios_base::sync_with_stdio(false); cin.tie(0);
    solve();
}
