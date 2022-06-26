#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

int n;
vector<vector<int>> capacity;
vector<vector<int>> adj;

int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, inf});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int maxflow(int s, int t) {
    int flow = 0;
    vector<int> parent(n);
    int new_flow;

    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] -= new_flow;
            cur = prev;
        }
    }

    return flow;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int cnt  = 1;
    while(cin >> n, n){
        int s, t, c; cin >> s >> t >> c;
        adj.assign(n, vector<int>());
        capacity.assign(n, vector<int>(n, 0));
        set<pair<int, int>> mySet;
        for (int i = 0; i < c; ++i){
            int a, b, w; cin >> a >> b >> w;
            --a; --b;
            if (!mySet.count({a, b}) && !mySet.count({b, a})){
                adj[a].push_back(b);
                adj[b].push_back(a);
                mySet.insert({a, b});
            }
            capacity[a][b] += w;
            capacity[b][a] += w;
        }
        cout << "Network " << cnt++ << '\n'
            << "The bandwidth is " << maxflow(s-1, t-1) << ".\n\n";
    }

	return 0;
}
