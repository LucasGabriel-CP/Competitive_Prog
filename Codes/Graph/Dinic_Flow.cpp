#include <bits/stdc++.h>

/*
* Normal: O(|V|^2 * |E|)
* Unit Network: O(|E| * sqrt(|V|))
* Unit Capacities: O(std::min(|E| * sqrt(|E|), |E| * |V| ^ (2/3)))
*/

struct Flow {
    static constexpr int INF = (int)1e9;
    int n;
    struct Edge {
        int to, cap;
        Edge(int to, int cap) : to(to), cap(cap) {}
    };

    std::vector<Edge> edges;
    std::vector<std::vector<int>> adj;
    std::vector<int> cur, h;

    Flow() { n = 0; }
    Flow(int n) : n(n), adj(n) {}
    bool bfs(int s, int t) {
        h.assign(n, -1);
        std::queue<int> que;
        h[s] = 0;
        que.push(s);
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            for (int i : adj[u]) {
                auto [v, c] = edges[i];
                if (c > 0 && h[v] == -1) {
                    h[v] = h[u] + 1;
                    if (v == t)
                        return true;
                    que.push(v);
                }
            }
        }
        return false;
    }

    int dfs(int u, int t, int f) {
        if (u == t)
            return f;
        int r = f;
        for (int& i = cur[u]; i < (int)adj[u].size(); ++i) {
            int j = adj[u][i];
            auto [v, c] = edges[j];
            if (c > 0 && h[v] == h[u] + 1) {
                int a = dfs(v, t, std::min(r, c));
                edges[j].cap -= a;
                edges[j ^ 1].cap += a;
                r -= a;
                if (r == 0)
                    return f;
            }
        }
        return f - r;
    }

    void addEdge(int u, int v, int c) {
        adj[u].push_back((int)edges.size());
        edges.emplace_back(v, c);
        adj[v].push_back((int)edges.size());
        edges.emplace_back(u, 0);
    }

    int maxFlow(int s, int t) {
        int ans = 0;
        while (bfs(s, t)) {
            cur.assign(n, 0);
            ans += dfs(s, t, INF);
        }
        return ans;
    }
};
