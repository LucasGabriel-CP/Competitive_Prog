#include<bits/stdc++.h>

using namespace std;

typedef int no;
const int maxn = 1e5 + 50, MAXLOGN = 18, inf = 1e9;

class SegTree{
private:
#define Mid ((l + r) >> 1)
#define nil 0
    int n;
    vector<no> lazy, seg;
    no modify(no &a, no &b){
        return a + b;
    }
    void push(int id, int child){
        no &l = lazy[id];
        if (l){
            seg[id] += l*(child+1);
            if (child){
                lazy[2*id] += l;
                lazy[2*id+1] += l;
            }
            l = 0;
        }
    }
    void build(int id, int l, int r, vector<int> const& vet){
        if(l == r) seg[id] = vet[l];
        else{
            build(2*id, l, Mid, vet);
            build(2*id+1, Mid+1, r, vet);
            seg[id] = modify(seg[2*id], seg[2*id+1]);
        }
    }
    no query(int id, int l, int r, int x, int y){
        push(id, r-l);
        if(x > r || y < l)   return nil;
        if(l >= x && r <= y) return seg[id];
        no p1 = query(2*id, l, Mid, x, y);
        no p2 = query(2*id+1, Mid+1, r, x, y);
        return modify(p1, p2);
    }
    void update(int id, int l, int r, int x, int y, no val){
        push(id, r-l);
        if(x > r || y < l)  return;
        if(l >= x && r <= y){
            lazy[id] += val;
            push(id, r-l);
            return;
        }
        update(2*id, l, Mid, x, y, val);
        update(2*id+1, Mid+1, r, x, y, val);
        seg[id] = modify(seg[2*id], seg[2*id+1]);
    }
public:
    SegTree(){};
    SegTree(vector<int> const& A){
        n = (int)A.size();
        seg.resize(4*n);
        lazy.assign(4*n, 0);
        build(1, 0, n-1, A);
    }
    no query(int x, int y){ return query(1, 0, n-1, x, y); }
    void update(int x, int y, no val){ update(1, 0, n-1, x, y, val); }
};

//Grafo, valor de cada vertice
vector<int> AdjList[maxn], vet;
//Segtree
SegTree tree;
//HLD
int arr[maxn], chainHead[maxn], parent[maxn], position[maxn], subtree_sz[maxn], chainId, pos;

void HLD(int u, int p = -1){
    position[u] = pos++;
    arr[position[u]] = vet[u];
    for (int v: AdjList[u]){
        if (v == p) continue;
        parent[v] = u;
        chainHead[v] = (v == AdjList[u][0] ? chainHead[u] : v);
        HLD(v, u);
    }
}

void dfs(int u, int p = -1){
    subtree_sz[u] = 1;
    for(int &v: AdjList[u]){
        if (p == v) continue;
        dfs(v, u);
        subtree_sz[u] += subtree_sz[v];
        if (subtree_sz[v] > subtree_sz[AdjList[u][0]] || AdjList[u][0] == p)
            swap(v, AdjList[u][0]);
    }
}

void build(int root = 0){
    dfs(root);
    pos = 0;
    chainHead[root] = root;
    HLD(root);
    tree = SegTree(vet);
}

int query_path(int u, int v){
    if (position[u] < position[v]) swap(u, v);
    if (chainHead[u] == chainHead[v]) return tree.query(position[v], position[u]);
    return tree.query(position[chainHead[u]], position[u]) + query_path(parent[chainHead[u]], v);
}

void upd_path(int u, int v, int val){
    if (position[u] < position[v]) swap(u, v);
    if (chainHead[u] == chainHead[v]){
        tree.update(position[v], position[u], val);
        return;
    }
    tree.update(position[chainHead[u]], position[u], val);
    upd_path(parent[chainHead[u]], v, val);
}
