#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10005, inf = 1e9;
int n, m, r;
vector<int> AdjList[MAXN];
bool vis[MAXN];
stack<int> Order;


void dfs(int u, bool topo = true){
    vis[u] = true;
    for (int v: AdjList[u])
        if (!vis[v]) dfs(v);
    if (topo)
        Order.push(u);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    for (int c = 1; c <= t; ++c){
        int ans = 0;
        cin >> n >> m;
        for (int i = 0; i < n; ++i){
            AdjList[i].clear(); vis[i] = false;
        }
        for (int i = 0; i < m; ++i){
            int a, b; cin >> a >> b;
            --a; --b; AdjList[a].push_back(b);
        }
        for (int i = 0; i < n; ++i){
            if (!vis[i]) dfs(i);
        }
        memset(vis, 0, n);
        for (; !Order.empty(); Order.pop()){
            if (!vis[Order.top()]){
                ++ans;
                dfs(Order.top(), false);
            }
        }

        cout << "Case " << c << ": " << ans << '\n';
    }

	return 0;
}
