#include <bits/stdc++.h>

using namespace std;

typedef int no;
const int maxn = 5*1e3 + 5, MAXLOGN = 17, inf = 1e9;

//Segment Tree class
class SegTree{
private:
    int n;
    no seg[4*maxn];
#define Mid ((l + r) >> 1)
#define nil 0
    no modify(no a, no b){
        return max(a, b);
    }
    void build(int id, int l, int r, const vector<int> &vet){
        if(l == r) seg[id] = vet[l];
        else{
            build(2*id, l, Mid, vet);
            build(2*id+1, Mid+1, r, vet);
            seg[id] = modify(seg[2*id], seg[2*id+1]);
        }
    }
    no query(int id, int l, int r, int x, int y){
        if(x > r || y < l)   return nil;
        if(l >= x && r <= y) return seg[id];
        no p1 = query(2*id, l, Mid, x, y);
        no p2 = query(2*id+1, Mid+1, r, x, y);
        return modify(p1, p2);
    }
    void update(int id, int l, int r, int x, no val){
        if(x > r || x < l)  return;
        if(l == x && r == x){
            seg[id] = val;
            return;
        }
        update(2*id, l, Mid, x, val);
        update(2*id+1, Mid+1, r, x, val);
        seg[id] = modify(seg[2*id], seg[2*id+1]);
    }
public:
    SegTree(){}
    SegTree(vector<int> const& A){
        n = (int)A.size();
        build(1, 0, n-1, A);
    }
    no query(int x, int y){ return query(1, 0, n-1, x, y); }
    void update(int x, no val){ update(1, 0, n-1, x, val); }
};

//graph vertex -> cost
vector<pair<int, int>> AdjList[maxn];
//Segtree
SegTree tree;
vector<int> arr;
//LCA
int parent[maxn][MAXLOGN], depth[maxn];
//HLD
int subtree_sz[maxn], chain[maxn], chainHead[maxn], position[maxn], chainId, pos;

void HLD(int u, int p){
    int heavyChild = -1, heavySz = 0, heavyEdgeWeight = -1;
    position[u] = pos++;
    chain[u] = chainId;
    for (pair<int, int> v: AdjList[u]){
        if (v.first == p || subtree_sz[v.first] <= heavySz) continue;
        heavyEdgeWeight = v.second;
        heavyChild = v.first;
        heavySz = subtree_sz[v.first];
    }
    if (heavyChild != -1){
        arr[pos] = heavyEdgeWeight;
        HLD(heavyChild, u);
    }
    for (pair<int, int> v: AdjList[u]){
        if (v.first == p || v.first == heavyChild) continue;
        chainHead[++chainId] = v.first;
        arr[pos] = v.second;
        HLD(v.first, u);
    }
}

void dfs(int u){
    subtree_sz[u]++;
    for(pair<int, int> v: AdjList[u]){
        if (v.first == parent[u][0]) continue;
        parent[v.first][0] = u;
        depth[v.first] = depth[u] + 1;
        dfs(v.first);
        subtree_sz[u] += subtree_sz[v.first];
    }
}

void computeParent(int root, const int &n){
    depth[root] = 0;
    parent[root][0] = root;
    dfs(root);

    for(int j = 1; j < MAXLOGN; j++){
        for(int i = 1; i <= n; i++)
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

//from -> left/right Node, to -> LCA of from
int queryUp(int from, int to){
    int cur = from, ans = 0;
    while(chain[cur] != chain[to]){
        //Modify the current answer
        ans = max(ans, tree.query(position[chainHead[chain[cur]]], position[cur]));
        cur = parent[chainHead[chain[cur]]][0];
    }
    //Modify the last answer
    ans = max(ans, tree.query(position[to]+1, position[cur]));
    return ans;
}

int query(int u, int v, int lca){
    int mx = queryUp(u, lca);
    mx = max(mx, queryUp(v, lca));
    return mx;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    //Init
    chainId = pos = 0;
    arr.resize(n);
    for (int i = 0; i < n; ++i)
        chain[i] = chainHead[i] = subtree_sz[i] = 0;
    int root = 0;
    computeParent(root, n);
    chainHead[0] = 1;
    HLD(root, -1);
    tree = SegTree(arr);
    //query -> u - v: u - lca & v - lca
    //update -> u, c: position[vertice mais fundo], c

	return 0;
}
