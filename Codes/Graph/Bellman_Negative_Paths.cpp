/*
	(ˆ ڡ ˆ)yum!
*/

typedef std::vector<int> vi;
typedef std::vector<std::pair<int, int>> vii;

const int maxn = (int)1e5, inf = (int)1e9;

int n;
vii AdjList[maxn];

int BellMan(int S, int D){
    vi dist(n, inf); dist[S] = 0;

    for(int i = 0; i < n - 1; ++i){
        bool modified = false;
        for (int u = 0; u < n; ++u){
            if (dist[u] != inf){
                for (auto to: AdjList[u]){
                    int v = to.first, w = to.second;
                    if (dist[u] + w >= dist[v]) continue;
                    dist[v] = dist[u] + w;
                    modified = true;
                }
            }
        }
        if (!modified) break;
    }

    bool NegativeCycle = false;
    for (int u = 0; u < n; ++u){
        if (dist[u] != inf){
            for (auto to: AdjList[u]){
                int v = to.first, w = to.second;
                if (dist[v] > dist[u] + w)
                    NegativeCycle = true;
            }
        }
    }

    if (NegativeCycle)
        return -inf;
    return dist[D];
}
