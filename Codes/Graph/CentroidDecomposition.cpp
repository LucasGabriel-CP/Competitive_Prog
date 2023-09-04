#include <bits/stdc++.h>

struct centroid {
    std::vector<std::vector<int>> adj;
    std::vector<bool> del;
    std::vector<int> par, sz;
    int n;
    centroid() { }
    centroid(int n_) {
        n = n_;
        adj = std::vector<std::vector<int>>(n, std::vector<int>());
        del = std::vector<bool>(n, false);
        par = std::vector<int>(n, -1);
        sz = std::vector<int>(n);
    }
    
    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int find_centroid(int u, int p, int tam) {
        for (int v: adj[u]) {
            if (v == p) continue;
            if (!del[v] && sz[v] * 2 > tam) {
                return find_centroid(v, u, tam);
            }
        }
        return u;
    }

    int calc_size(int u, int p = -1) {
        if (del[u]) return 0;
        sz[u] = 1;
        for (int v: adj[u]) {
            if (v == p) continue;
            sz[u] += calc_size(v, u);
        }
        return sz[u];
    }

    void init(int u = 0, int p = -1) {
        calc_size(u);
        int cent = find_centroid(u, -1, sz[u]);
        
        // do stuff here
        
        del[cent] = true;
        par[cent] = p;
        for (int v: adj[cent]) {
            if (del[v]) continue;
            init(v, cent);
        }
    }
};