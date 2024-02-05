/*
* Simple matching
* Complexity: O(|V| * |E|)
*/

int n, k;
std::vector<std::vector<int>> g;
std::vector<int> mt;
std::vector<bool> vis;

bool dfs(int u) {
    if (vis[u])
        return false;
    vis[u] = true;
    for (int v : g[u]) {
        if (mt[v] == -1 || dfs(mt[v])) {
            mt[v] = u;
            return true;
        }
    }
    return false;
}

void kuhn() {
    mt.assign(k, -1);
    std::vector<bool> used(n, false);
    for (int u = 0; u < n; ++u) {
        for (int v : g[u]) {
            if (mt[v] == -1) {
                mt[v] = u;
                used[u] = true;
                break;
            }
        }
    }
    for (int u = 0; u < n; ++u) {
        if (used[u]) continue;
        vis.assign(n, false);
        dfs(u);
    }
}