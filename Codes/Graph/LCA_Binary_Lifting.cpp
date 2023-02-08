#include<bits/stdc++.h>

const int maxn = (int)1e5 + 5, maxlogn = 19;
std::vector<int> AdjList[maxn];
int depth[maxn], parent[maxn][maxlogn], n;

void dfs(int u){
    for(int v : AdjList[u]) {
        if(v == parent[u][0]) continue;
        parent[v][0] = u;
        depth[v] = depth[u] + 1;
        dfs(v);
    }
}

void computeParent(int root) {
    depth[root] = 0;
    parent[root][0] = root;
    dfs(root);

    for(int j = 1; j < maxlogn; j++){
        for(int i = 1; i <= n; i++)
            parent[i][j] = parent[parent[i][j-1]][j-1];
    }
}

int LCA(int u, int v){
    if(depth[u] > depth[v]) std::swap(u, v);
    int d = depth[v] - depth[u];
    for(int i = 0; i < maxlogn; i++){
        if(d & (1 << i)){
            v = parent[v][i];
        }
    }
    if(u == v)  return u;
    for(int i = maxlogn-1; i >= 0; i--){
        if (parent[u][i] != parent[v][i]){
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}
