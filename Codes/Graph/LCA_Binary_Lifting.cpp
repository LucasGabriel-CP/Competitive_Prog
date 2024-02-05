/*
	(ˆ ڡ ˆ)yum!
*/

const int maxn = (int)1e5 + 5, maxlogn = 19;

struct lcaBinLift {
    std::vector<std::vector<int>> adj, parent;
    std::vector<int> depth;
    int n;
    lcaBinLift() { }
    lcaBinLift(int n_) {
        n = n_;
        adj = std::vector<std::vector<int>>(n + 1, std::vector<int>());
        parent = std::vector<std::vector<int>>(n + 1, std::vector<int>(maxlogn, -1));
        depth = std::vector<int>(n + 1);
    }

    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int u){
        for(int v : adj[u]) {
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

    int get_lca(int u, int v){
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
};