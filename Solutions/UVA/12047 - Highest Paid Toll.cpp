#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10005, inf = 1e9;
int n, m, r;
vector<pair<int, int>> AdjList[MAXN];
vector<pair<int, int>> AdjListR[MAXN];
int dist[MAXN];

void dijkstra(int o){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater <pair<int, int>>> myPq;
    myPq.push({0, o});
    dist[o] = 0;
    while(!myPq.empty()){
        int d = myPq.top().first;
        int u = myPq.top().second;
        myPq.pop();
        if (d > dist[u]) continue;
        for (auto it : AdjList[u]){
            int v = it.first, w = it.second;
            if (dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                myPq.push({dist[v], v});
            }
        }
    }
}

void dijkstraRe(int o){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater <pair<int, int>>> myPq;
    myPq.push({0, o});
    vector<int> distR(n, inf);
    distR[o] = 0;
    int ans = -1;
    while(!myPq.empty()){
        int d = myPq.top().first;
        int u = myPq.top().second;
        myPq.pop();
        if (d > distR[u]) continue;
        for (auto it : AdjListR[u]){
            int v = it.first, w = it.second;
            if (dist[v] + w + d <= r){
                ans = max(ans, w);
            }
            if (distR[v] > distR[u] + w){
                distR[v] = distR[u] + w;
                myPq.push({distR[v], v});
            }
        }
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int s, c, t; cin >> c;
    while(c--){
        cin >> n >> m >> s >> t >> r;
        for (int i = 0; i < n; ++i){ dist[i] = inf; AdjList[i].clear(); AdjListR[i].clear(); }
        for (int i = 0; i < m; ++i){
            int a, b, p; cin >> a >> b >> p;
            --a; --b;
            AdjList[a].push_back({b, p});
            AdjListR[b].push_back({a, p});
        }
        dijkstra(s-1);
        dijkstraRe(t-1);
    }

	return 0;
}
