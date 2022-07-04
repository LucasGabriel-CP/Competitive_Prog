#include <bits/stdc++.h>

using namespace std;

const int maxn = 125, inf = 1e9, mod = 1000007;
int dist[maxn][maxn], graph[maxn][maxn], p[maxn][maxn], n, m, boss, office, home, market;

void floyd(unordered_set<int> myHash = {}){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!myHash.count(i) && !myHash.count(j) && graph[i][j] != inf){
                dist[i][j] = graph[i][j];
                p[i][j] = j;
            }
            else{
                dist[i][j] = inf;
                p[i][j] = -1;
            }
        }
    }
    for (int k = 0; k < n; ++k) {
        if (myHash.count(k)) continue;
        for (int i = 0; i < n; ++i) {
            if (myHash.count(i)) continue;
            for (int j = 0; j < n; ++j) {
                if (!myHash.count(j) && dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                    p[i][j] = p[i][k];
                }
            }
        }
    }
}

void Remove(int u, int v, unordered_set<int> &myHash){
    if (p[u][v] == -1) return;
    graph[u][v] = graph[v][u] = inf;
    myHash.insert(u);
    while(u != v){
        u = p[u][v];
        myHash.insert(u);
        graph[u][v] = graph[v][u] = inf;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> n >> m >> boss >> office >> home >> market){
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j)
                graph[i][j] = inf;
            graph[i][i] = 0;
        }
        for (int i = 0; i < m; ++i){
            int a, b, c; cin >> a >> b >> c;
            graph[a-1][b-1] = c;
            graph[b-1][a-1] = c;
        }
        floyd();
        unordered_set<int> myHash;
        --boss; --office; --home; --market;
        int res = dist[boss][office], aux = n;
        while(aux && res == dist[boss][office]){
            Remove(boss, office, myHash);
            floyd();
            --aux;
        }
        myHash.insert(boss);
        myHash.insert(office);
        floyd(myHash);
        if (dist[home][market] == inf) cout << "MISSION IMPOSSIBLE.\n";
        else cout << dist[home][market] << '\n';
    }

    return 0;
}
