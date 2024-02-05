//works on O(V+E)

/*
	(ˆ ڡ ˆ)yum!
*/

using namespace std;

const int maxn = 1e5, inf = 1e9;
vector<pair<int, int>> AdjList[maxn];
stack<int> S;
bool vis[maxn];

void dfs(int u){
    vis[u] = true;
    for (auto[v, _] : AdjList[u])
        if (!vis[v]) dfs(v);
    S.push(u);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, dest, orig;
    cin >> n >> m >> orig >> dest;
    for (int i = 0; i < m; ++i){
        int a, b, p; cin >> a >> b >> p;
        --a; --b; //for array range
        AdjList[a].push_back({b, p}); //p * -1 for longest
    }

    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; ++i)
        if (!vis[i])
            dfs(i);

    vector<int> dist(n, inf);
    dist[orig] = 0;
    for (; !S.empty(); S.pop()){
        int u = S.top();
        if (dist[u] != inf){
            for (pair<int, int> to : AdjList[u]){
                int v = to.first, w = to.second;
                dist[v] = min(dist[v], dist[u] + w);
            }
        }
    }

    cout << dist[dest] << '\n';
    //cout << dist[dest] * -1 << '\n'; for longest
}
