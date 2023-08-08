#include <bits/stdc++.h>

std::vector<int> topo_sort(std::vector<std::vector<int>> adj) {
    std::vector<int> in((int)adj.size() + 1), ret;
    for (auto &u: adj) {
        for (int v: u) {
            in[v]++;
        }
    }
    std::queue<int> q;
    for (int i = 0; i < (int)adj.size(); i++) {
        if (!in[i]) q.push(i);
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        ret.push_back(u);
        for (int v: adj[u]) {
            if (--in[v] == 0) q.push(v);
        }
    }
    if ((int)ret.size() != (int)adj.size())
        return std::vector<int>();
    return ret;
}