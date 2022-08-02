#include <bits/stdc++.h>

using namespace std;

typedef int no;
const int maxn = 100050, MAXLOGN = 17, inf = 1e9;

vector<int> AdjList[maxn];
bool cor[maxn];
set<int> turned[maxn];
int parent[maxn][MAXLOGN], depth[maxn];
int subtree_sz[maxn], chain[maxn], chainHead[maxn], position[maxn], node[maxn], chainId, pos;

void HLD(int u, int p){
    int heavyChild = -1, heavySz = 0;
    node[pos] = u;
    position[u] = pos++;
    chain[u] = chainId;
    for (int v: AdjList[u]){
        if (v == p || subtree_sz[v] <= heavySz) continue;
        heavyChild = v;
        heavySz = subtree_sz[v];
    }
    if (heavyChild != -1){
        HLD(heavyChild, u);
    }
    for (int v: AdjList[u]){
        if (v == p || v == heavyChild) continue;
        chainHead[++chainId] = v;
        HLD(v, u);
    }
}

void dfs(int u){
    subtree_sz[u]++;
    for(int v: AdjList[u]){
        if (v == parent[u][0]) continue;
        parent[v][0] = u;
        depth[v] = depth[u] + 1;
        dfs(v);
        subtree_sz[u] += subtree_sz[v];
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

int queryUp(int to){
    int ans = -1;
    while(to){
        if (!turned[chain[to]].empty()){
            int pos = *turned[chain[to]].begin();
            if (pos <= position[to]){
                ans = node[pos];
            }
        }
        to = parent[chainHead[chain[to]]][0];
    }
    return ans;
}

void upd(int v){
    cor[v] = !cor[v];
    if (cor[v]) turned[chain[v]].insert(position[v]);
    else turned[chain[v]].erase(position[v]);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q; cin >> n >> q;
    for (int i = 0; i < n-1; i++){
        int a, b, c; cin >> a >> b;
        AdjList[a].emplace_back(b);
        AdjList[b].emplace_back(a);
    }
    chainId = pos = 0;
    for (int i = 0; i <= n; ++i){
        cor[i] = chain[i] = chainHead[i] = subtree_sz[i] = 0;
    }
    int root = 1;
    computeParent(root, n);
    chainHead[root] = 1;
    HLD(root, -1);
    while(q--){
        int a, b; cin >> a >> b;
        if (a) cout << queryUp(b) << '\n';
        else upd(b);
    }

	return 0;
}
