#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
typedef long long ll;

const int MAXN = 550;
const long long inf = 1e14;

int n, m, cnt;
bool vis[MAXN];
ll dist[MAXN];
vii AdjList[MAXN];

void dfs(int u, ll val){
    ++cnt;
    vis[u] = true;
    for (ii v : AdjList[u]){
        if (!vis[v.first] && (ll)v.second == val){
            dfs(v.first, val);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> n >> m, n && m){
        int a, b, p;
        for (int i = 0; i < n; ++i){
            AdjList[i].clear();
            vis[i] = false;
            dist[i] = -inf;
        }
        ll maior = -inf;
        for (int i = 0; i < m; ++i){
            cin >> a >> b >> p;
            --a; --b;
            dist[a] = (p > dist[a] ? p : dist[a]);
            dist[b] = (p > dist[b] ? p : dist[b]);
            maior = (p > maior ? p : maior);
            AdjList[a].push_back({b, p});
            AdjList[b].push_back({a, p});
        }
        int ans = 1;
        for (int i = 0; i < n; ++i){
            if (!vis[i] && dist[i] == maior){
                cnt = 0;
                dfs(i, maior);
                ans = max(ans, cnt);
            }
        }
        cout << ans << '\n';
    }

	return 0;
}
