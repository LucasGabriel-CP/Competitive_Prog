#define MAXN 100005
#define MAXLOGN 10

vector<int> AdjList[MAXN];
int depth[MAXN], parent[MAXN][MAXLOGN];

void dfs(int u, int v){
    for(auto v : AdjList[u]) {
        if(v == parent[u][0]) continue;
        parent[v][0] = u;
        depth[v] = depth[u] + 1;
        dfs(v.f);
    }
}

void computeParent(int root) {
    depth[root] = 0;
    parent[root][0] = root;
    dfs(root);

    for(int j = 1; j < MAXLOGN; j++){
        for(int i = 1; i <= N; i++)
            parent[i][j] = parent[parent[i][j-1]][j-1];
    }
}

int LCA(int u, int v){
    if(depth[u] > depth[v]) swap(u, v);
    int d = depth[v] - depth[u];
    for(int i = 0; i < MAXLOGN; i++)
        if(d & (1 << i))
            v = parent[v][i];

    if(u == v)  return u;
    for(int i = MAXLOGN-1; i >= 0; i--){
        while(parent[u][i] != parent[v][i]){
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}
