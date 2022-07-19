#include <bits/stdc++.h>

using namespace std;

vector<int> AdjList[20005], tin, low;
bool vis[20005];
int Timer;
set<int> ans;

void dfs(int u, int p = -1){
    int child = 0;
    vis[u] = true;
    tin[u] = low[u] = Timer++;
    for (int v : AdjList[u]){
        if (!vis[v]){
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] >= tin[u] && p != -1){
                ans.insert(u);
            }
            ++child;
        }
        else{
            low[u] = min(low[u], tin[v]);
        }
    }
    if (child > 1 && p == -1) ans.insert(u);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, t;
    while(cin >> n >> m, n || m){
        for (int i = 0; i < n; ++i){
            AdjList[i].clear();
            vis[i] = false;
        }
        tin.resize(n);
        low.resize(n);
        for (int i = 0; i < m; ++i){
            int a, b; cin >> a >> b;
            --a; --b;
            AdjList[a].push_back(b);
            AdjList[b].push_back(a);
        }
        ans.clear();
        Timer = 0;
        for (int i = 0; i < n; ++i){
            if (!vis[i]){
                dfs(i);
            }
        }
        cout << ans.size() << '\n';
    }
	return 0;
}
