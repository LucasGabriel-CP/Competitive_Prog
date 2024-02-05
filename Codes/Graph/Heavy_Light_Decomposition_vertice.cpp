/*
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣠⣤⣤⣤⣤⣀⠀⠀
⠀⣤⡶⠶⠶⠶⠶⢦⣤⣄⣀⣠⣤⡶⠶⠿⠿⠛⠛⠛⠛⠻⠿⠶⠶⣦⣤⣀⣀⣴⠾⠟⠋⠉⢀⣀⣀⠀⢻⡆⠀
⠀⣿⠀⡆⠀⠀⣒⣢⡄⠉⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠉⠁⠠⢔⣒⠉⠉⠀⢈⠀⢸⠇⠀
⠀⣿⠀⡇⢀⣬⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⠚⠥⡄⢸⠀⣿⠀⠀
⠀⣿⠀⣇⡴⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢦⡌⠀⣿⠀⠀
⠀⢿⣄⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⣸⡇⠀⠀
⠀⣼⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⣿⡄⠀
⠀⡿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠘⣷⠀
⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⡀
⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇
⠸⣧⠀⠀⠀⠀⠀⠀⠀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⢸⡇
⠀⣿⠀⠀⠀⠀⠀⢠⣿⣿⣿⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⡆⠀⠀⢀⣀⣤⣴⣤⣤⣄⣀⠀⡸⠀⢸⡇
⢠⡟⠀⠀⠀⠀⣀⣘⣿⣿⡿⠃⠀⠀⠀⢀⣆⠀⠀⠀⠀⠈⠻⠿⠟⣁⢀⣴⡟⡫⢟⣒⣒⡢⢍⠛⢷⣅⠀⣾⠁
⠘⣧⠀⠀⠀⠎⠀⠀⢹⠀⠀⠀⠀⠀⠀⠛⠉⠓⠀⠀⠀⠀⠀⠀⣎⢠⡿⡳⢫⢞⣡⣤⣤⣌⢣⣱⡈⣿⣶⡟⠀
⠀⢿⡀⠀⠀⠈⠁⠈⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣿⣧⢳⢣⡿⣳⢺⣿⣿⡇⡇⡇⢹⣿⠀⠀
⠀⠈⢿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⣿⣸⣸⣣⣧⣘⢛⣻⣇⣷⠇⣼⣿⠀⠀
⠀⠀⠀⠈⠛⠷⢦⣤⣤⣤⣤⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣨⣿⣧⡧⣑⢷⣫⣭⣽⠿⢋⣼⣾⠇⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠈⣹⡟⠁⠀⠀⣀⢀⣀⣀⣀⠀⣀⣄⣀⣠⡾⣿⣿⡿⢿⣮⣁⣛⣛⣋⣩⣿⠿⠃⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⢰⡟⠁⠀⠀⠀⠉⠛⠉⠉⠙⣿⡋⠉⠉⠙⠛⠛⠃⠈⠒⢬⠉⠛⣿⡉⠉⠁⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⢀⣾⠃⠀⠀⠀⠀⠀⠀⢀⣠⣾⣿⣷⣤⣀⠀⠀⠀⠀⠀⠀⠈⠇⠀⠘⣷⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀⠰⠶⠾⠛⠋⣿⣿⠟⠉⠛⠻⠶⠶⠶⠀⠀⠀⠘⡄⠀⢹⣇⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢡⠀⠀⢿⡄⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠘⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⠂⠀⠘⠃⠀⠀⠀⠀⠀
*/

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
    SegTree(std::vector<T> const& A){
        n = (int)A.size();
        seg.resize(4*n);
        lazy.assign(4*n, 0);
        build(1, 0, n-1, A);
    }
    T query(int x, int y){ return query(1, 0, n-1, x-1, y-1); }
    void update(int x, int y, T val){ update(1, 0, n-1, x-1, y-1, val); }
};

//HLD
template<typename T>
struct hld{
    SegTree<T> tree;
    std::vector<T> arr, chainHead, parent, position, subtree_sz;
    std::vector<std::vector<int>> adj;
    int chainId, pos;
    void init(int n){
        adj.resize(n + 1); chainHead.resize(n + 1);
        parent.resize(n + 1); position.resize(n + 1);
        subtree_sz.resize(n + 1); arr.resize(n);
    }
    void add_edge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void HLD(int u, std::vector<T> const& vet, int p = -1){
        position[u] = pos++;
        arr[position[u]] = vet[u];
        for (int v: adj[u]){
            if (v == p) continue;
            parent[v] = u;
            chainHead[v] = (v == adj[u][0] ? chainHead[u] : v);
            HLD(v, vet, u);
        }
    }
    void dfs(int u, int p = -1){
        subtree_sz[u] = 1;
        for(int &v: adj[u]){
            if (p == v) continue;
            dfs(v, u);
            subtree_sz[u] += subtree_sz[v];
            if (subtree_sz[v] > subtree_sz[adj[u][0]] || adj[u][0] == p)
                std::swap(v, adj[u][0]);
        }
    }
    void build(int root, std::vector<T> const& vet){
        dfs(root);
        pos = 0;
        chainHead[root] = root;
        HLD(root);
        tree = SegTree(arr);
    }
    T query_path(int u, int v){
        if (position[u] < position[v]) std::swap(u, v);
        if (chainHead[u] == chainHead[v]) return tree.query(position[v], position[u]);
        return tree.query(position[chainHead[u]], position[u]) + query_path(parent[chainHead[u]], v);
    }

    void upd_path(int u, int v, T val){
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
    T query_subtree(int a) {
        return tree.query(position[a], position[a] + subtree_sz[a]-1);
    }
    void update_subtree(int a, int x) {
        tree.update(position[a], position[a]+subtree_sz[a]-1, x);
    }
};

