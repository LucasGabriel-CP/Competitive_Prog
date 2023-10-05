#include <bits/stdc++.h>
using i64 = long long;


//O((N^2)(M^2)) with bellmanford/spaf
//O((N^3)M) with dijkstra
namespace mcmf {
    struct edge{
        int from, to;
        i64 cap, cost;
        edge(){}
        edge(int f, int t, i64 cap_, i64 c){ from = f; to = t; cap = cap_; cost = c; }
    };

    const int maxn = 305;
    const long long inf64 = (long long)1e18;
    std::vector<std::vector<int>> adj;
    std::vector<edge> edges;
    bool inq[maxn];
    int p[maxn];
    i64 d[maxn];
    int n;

    void init(int _n) {
        n = _n;
        adj = std::vector<std::vector<int>>(n + 1);
    }


    bool spfa(int source, int sink){
        for (int i = 0; i < maxn; i++) d[i] = inf64;
        memset(p, -1, sizeof(p));
        memset(inq, 0, sizeof(inq));
        std::queue<int> q;
        q.push(source);
        d[source] = 0;
        while (!q.empty()){
            int u = q.front();
            inq[u] = false;
            q.pop();
            for (int v: adj[u]){
                edge e = edges[v];
                if (e.cap > 0 && d[e.to] > d[u] + e.cost){
                    d[e.to] = d[u] + e.cost;
                    p[e.to] = v;
                    if (!inq[e.to]){
                        inq[e.to] = true;
                        q.push(e.to);
                    }
                }
            }
        }
        return d[sink] != inf64;
    }

    void add(int u, int v, i64 cap, i64 cost){
        edges.emplace_back(u, v, cap, cost);
        edges.emplace_back(v, u, 0, -cost);
        adj[u].push_back(edges.size()-2);
        adj[v].push_back(edges.size()-1);
    }

    i64 minCost(int source, int sink){
        i64 flow = 0, cost = 0;
        while(spfa(source, sink)){
            i64 f = inf64;
            int cur = p[sink];
            while(cur != -1){
                f = std::min(f, edges[cur].cap);
                cur = p[edges[cur].from];
            }
            cur = p[sink];
            while(cur != -1){
                edge &going = edges[cur];
                edge &turn = edges[cur^1];
                going.cap -= f;
                turn.cap += f;
                cur = p[going.from];
            }
            flow  += f;
            cost += f*d[sink];
        }
        return cost;
    }
};