#include <bits/stdc++.h>

using namespace std;

const int maxn = 125, inf = 1e9;
vector<pair<int, int>> AdjList[maxn][maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    string str;
    while(cin >> str){
        int n, m; cin >> n >> m;
        for (int i = 0; i < n - 1; ++i){
            for (int k = 1; k <= m; ++k){
                for (int j = 1; j <= m; ++j){
                    int val; cin >> val;
                    AdjList[i][k].push_back({val, j});
                }
            }
        }
        vector<vector<int>> dist(n, vector<int>(m + 1, inf));
        for (int i = 1; i <= m; ++i) dist[0][i] = 0;
        for (int u = 0; u < n - 1; u++){
            for (int i = 1; i <= m; ++i){
                for (pair<int, int> v: AdjList[u][i]){
                    dist[u + 1][v.second] = min(dist[u + 1][v.second], dist[u][i] + v.first);
                }
            }
        }
        int ans = inf;
        for (int i: dist[n-1]) ans = min(ans, i);
        for (int i = 0; i < n - 1; ++i){
            for (int k = 1; k <= m; ++k){
                AdjList[i][k].clear();
            }
        }
        cout << str << '\n' << ans + (n-1) * 2 << '\n';
    }
}
