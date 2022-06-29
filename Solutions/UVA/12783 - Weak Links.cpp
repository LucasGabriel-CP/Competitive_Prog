#include <bits/stdc++.h>

using namespace std;

const int maxn = 1005, inf = 1e9;
int n, m, timer;
vector<bool> vis;
vector<int> AdjList[maxn], tin, low;
vector<pair<int, int>> Bridge;

void dfs(int u, int p = -1){
	vis[u] = true;
	tin[u] = low[u] = timer++;
	for (int v: AdjList[u]){
		if (v == p) continue;
		if (vis[v])
			low[u] = min(low[u], tin[v]);
		else{
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if (low[v] > tin[u])
				Bridge.push_back({min(u, v), max(u, v)});
		}
	}
}

void FindBridge(){
	timer = 0;
	vis.assign(n, false);
	tin.assign(n, -1);
	low.assign(n, -1);
	Bridge.clear();
	for (int i = 0; i < n; i++){
		if (!vis[i])
			dfs(i);
	}
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int v, t;
    while(cin >> n >> m, n || m){
        for(int i = 0; i < n; ++i) AdjList[i].clear();
        for (int i = 0; i < m; ++i){
            int a, b; cin >> a >> b;
            AdjList[a].push_back(b);
            AdjList[b].push_back(a);
        }
        FindBridge();
        sort(Bridge.begin(), Bridge.end());
        cout << Bridge.size();
        for (pair<int, int> i: Bridge) cout << ' ' << i.first << ' ' << i.second;
        cout << '\n';
    }
}
