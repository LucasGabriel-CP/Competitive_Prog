#include <bits/stdc++.h>

const int maxn = 1005;

int n, m, timer;
std::vector<bool> vis;
std::vector<int> AdjList[maxn], tin, low;
std::vector<std::pair<int, int>> Bridge;

void dfs(int u, int p = -1){
    vis[u] = true;
    tin[u] = low[u] = timer++;
    for (int v: AdjList[u]){
        if (v == p) continue;
        if (vis[v])
            low[u] = std::min(low[u], tin[v]);
        else{
            dfs(v, u);
            low[u] = std::min(low[u], low[v]);
            if (low[v] > tin[u])
                Bridge.push_back({std::min(u, v), std::max(u, v)});
        }
    }
}

void FindBridge(){
    timer = 0;
    vis.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    Bridge.clear();
    for (int i = 0; i < n; i++){
        if (!vis[i])
            dfs(i);
    }
}
