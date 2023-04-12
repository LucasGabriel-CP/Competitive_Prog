#include<bits/stdc++.h>

const int maxn = 1e5 + 50, MAXLOGN = 18, inf = 1e9;

template<typename T>
class SegTree{
private:
    #define Mid ((l + r) >> 1)
    #define nil 0
    int n;
    std::vector<T> lazy, seg;
    T modify(T &a, T &b){
        return T(a + b);
    }
    void push(int id, bool child){
        T &l = lazy[id];
        if (l){
            seg[id] += l;
            if (child){
                lazy[2*id] += l;
                lazy[2*id+1] += l;
            }
            l = 0;
        }
    }
    void build(int id, int l, int r, std::vector<T> const& vet){
        if(l == r) seg[id] = vet[l];
        else{
            build(2*id, l, Mid, vet);
            build(2*id+1, Mid+1, r, vet);
            seg[id] = modify(seg[2*id], seg[2*id+1]);
        }
    }
    T query(int id, int l, int r, int x, int y){
        push(id, r-l);
        if(x > r || y < l)   return nil; //doens't change ans
        if(l >= x && r <= y) return seg[id];
        T p1 = query(2*id, l, Mid, x, y);
        T p2 = query(2*id+1, Mid+1, r, x, y);
        return modify(p1, p2);
    }
    void update(int id, int l, int r, int x, int y, T val){
        push(id, r-l);
        if(x > r || y < l)  return;
        if(l >= x && r <= y){
            lazy[id] = val;
            push(id, r-l);
            return;
        }
        update(2*id, l, Mid, x, y, val);
        update(2*id+1, Mid+1, r, x, y, val);
        seg[id] = modify(seg[2*id], seg[2*id+1]);
    }
public:
    SegTree(){ }
    SegTree(std::vector<int> const& A){
        n = (int)A.size();
        seg.resize(4*n);
        lazy.assign(4*n, 0);
        build(1, 0, n-1, A);
    }
    T query(int x, int y){ return query(1, 0, n-1, x, y); }
    void update(int x, int y, T val){ update(1, 0, n-1, x, y, val); }
};

//Grafo
//HLD
template<typename T>
struct hld{
    SegTree<T> tree;
    std::vector<T> vet, arr, chainHead, parent, position, subtree_sz;
    std::vector<std::vector<std::pair<int, T>>> adj;
    int chainId, pos;
    void init(int n){
        adj.resize(n + 1); chainHead.resize(n + 1);
        parent.resize(n + 1); position.resize(n + 1);
        subtree_sz.resize(n + 1); vet.resize(n + 1);
        arr.resize(n);
    }
    void add_edge(int u, int v, T w){
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    void HLD(int u, int p = -1){
        position[u] = pos++;
        arr[position[u]] = vet[u];
        for (auto &i: adj[u]){
            auto [v, w] = i;
            if (v == p) continue;
            parent[v] = u;
            chainHead[v] = (i == adj[u][0] ? chainHead[u] : v);
            HLD(v, u);
        }
    }
    void dfs(int u, int p = -1){
        subtree_sz[u] = 1;
        for(auto &i: adj[u]){
            auto [v, w] = i;
            if (p == v) continue;
            dfs(v, u);
            vet[v] = w;
            subtree_sz[u] += subtree_sz[v];
            if (subtree_sz[v] > subtree_sz[adj[u][0].first] || adj[u][0].first == p)
                std::swap(i, adj[u][0]);
        }
    }
    void build(int n, int root = 0){
        dfs(root);
        pos = 0;
        chainHead[root] = root;
        HLD(root);
        tree = SegTree(arr);
    }
    int query_path(int u, int v){
        if (u == v) return;
        if (position[u] < position[v]) std::swap(u, v);
        if (chainHead[u] == chainHead[v]) return tree.query(position[v], position[u]);
        return tree.query(position[chainHead[u]], position[u]) + query_path(parent[chainHead[u]], v);
    }

    void upd_path(int u, int v, int val){
        if (u == v) return;
        if (position[u] < position[v]) std::swap(u, v);
        if (chainHead[u] == chainHead[v]){
            tree.update(position[v], position[u], val);
            return;
        }
        tree.update(position[chainHead[u]], position[u], val);
        upd_path(parent[chainHead[u]], v, val);
    }
    int lca(int u, int v) {
        if (position[u] < position[v]) std::swap(u, v);
        return chainHead[u] == chainHead[v] ? v : lca(parent[chainHead[u]], v);
    }
    //Soma acumulada na subárvore
    Node query_subtree(int a) {
        if (subtree_sz[a] == 1) return 0;
        return tree.query(position[a], position[a] + subtree_sz[a]-1);
    }
    void update_subtree(int a, int x) {
        if (subtree_sz[a] == 1) return;
        tree.update(position[a], position[a]+subtree_sz[a]-1, x);
    }
};
