#include <bits/stdc++.h>

using namespace std;

const int maxn = 5*1e3 + 5, inf = 1e9;
int n, m;
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
    vector<int> parent(8+2*m);
    int new_flow;

    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t, ln = 1; cin >> t;
    while(t--){
        cin >> n >> m;
        adj.assign(8+2*m, vector<int>());
        capacity.assign(8+2*m, vector<int>(8+2*m, 0));
        map<string, int> myMap;
        int k = m+1;
        for (int i = 1; i <= m; i++){
            string a, b; cin >> a >> b;
            if (!myMap.count(a)) myMap[a] = k++;
            if (!myMap.count(b)) myMap[b] = k++;
            adj[i].push_back(myMap[a]);
            adj[myMap[a]].push_back(i);
            adj[i].push_back(myMap[b]);
            adj[myMap[b]].push_back(i);
            capacity[i][myMap[a]] = 1;
            capacity[myMap[a]][i] = 1;
            capacity[i][myMap[b]] = 1;
            capacity[myMap[b]][i] = 1;
        }
        for (int i = 1; i <= m; i++){
            adj[0].push_back(i);
            adj[i].push_back(0);
            capacity[0][i] = 1;
            capacity[i][0] = 1;
        }
        for (int i = m+1; i < k; i++){
            adj[i].push_back(k);
            adj[k].push_back(i);
            capacity[i][k] = n/6;
            capacity[k][i] = n/6;
        }
        cout << (maxflow(0, k) >= m ? "YES\n" : "NO\n");
    }

	return 0;
}
