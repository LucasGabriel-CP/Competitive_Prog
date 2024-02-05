using i64 = long long;
std::map<std::vector<int>, int> mphash;

struct tree {
    int n;
    i64 thash = -1;
    std::vector<std::vector<int>> adj;
    std::vector<int> sz, cs;
    tree(int n_) : n(n_), adj(n_ + 1), sz(n_ + 1) { }
    void add_edge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void dfs(int u, int p = -1){
        sz[u] = 1;
        bool cent = true;
        for (int v: adj[u]){
            if (p == v) continue;
            dfs(v, u); sz[u] += sz[v];
            if (sz[v] > n/2) cent = false;
        }
        if (cent && n - sz[u] <= n/2) cs.push_back(u);
    }
    int fhash(int u, int p = -1){
        std::vector<int> h;
        for (int v: adj[u]){
            if (v != p)
                h.push_back(fhash(v, u));
        }
        std::sort(h.begin(), h.end());
        if (!mphash.count(h)) mphash[h] = (int)mphash.size();
        return mphash[h];
    }
    i64 get_hash(){
        if (thash == -1){
            cs.clear();
            dfs(1);
            if ((int)cs.size() == 1) thash = fhash(cs[0]);
            else{
                i64 h1 = fhash(cs[0], cs[1]), h2 = fhash(cs[1], cs[0]);
                thash = (std::min(h1, h2) << 30) + std::max(h1, h2);
            }
        }
        return thash;
    }
};
