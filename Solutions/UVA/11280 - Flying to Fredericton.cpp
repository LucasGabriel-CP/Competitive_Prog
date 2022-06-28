#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105, inf = 1e9;
int n, m;
vector<pair<int, int>> AdjList[MAXN];
int dist[MAXN][MAXN];

void dijkstra(int o = 0){
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> myPq;
    for(int i = 0;i < n; i++){
        for (int j = 0; j < n; j++)
            dist[i][j] = inf;
    }
    dist[o][0] = 0;
    myPq.push({0, {o, -1}});
    while(!myPq.empty()){
        int d = myPq.top().first;
        int u = myPq.top().second.first;
        int k = myPq.top().second.second;
        myPq.pop();
        if (d != dist[u][k]) continue;
        for (auto it : AdjList[u]){
            int v = it.first, w = it.second;
            if (dist[v][k+1] > d + w){
                dist[v][k + 1] = d + w;
                myPq.push({d + w, {v, k + 1}});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    string a, b;
    int t, p; cin >> t;
    for (int c = 1; c <= t; ++c){
        cin >> n;
        unordered_map<string, int> myHash;
        for (int i = 0; i < n; ++i){
            AdjList[i].clear();
            cin >> a;
            myHash[a] = i;
        }
        cin >> m;
        while(m--){
            cin >> a >> b >> p;
            AdjList[myHash[a]].push_back({myHash[b], p});
        }
        dijkstra();
        cout << "Scenario #" << c << '\n';
        int q; cin >> q;
        for (int i = 0; i < q; ++i){
            int a, k;
            cin >> k;
            k = min(k, n-1);
            int ans = inf;
            while(k >= 0){
                ans = min(ans, dist[n-1][k--]);
            }
            if (ans != inf)
                cout << "Total cost of flight(s) is $" << ans << '\n';
            else
                cout << "No satisfactory flights\n";
        }
        if (c < t) cout << '\n';
    }

	return 0;
}
