#include <bits/stdc++.h>

using namespace std;

const int maxn = 125, inf = 1e9;
vector<pair<int, int>> AdjList[maxn];
vector<vector<int>> dist;
int matrix[maxn][maxn], jump, n;

void dfs(int i, int j){
    for (int k = 1; k <= jump; ++k){
        if (i + k < n && matrix[i][j] < matrix[i+k][j] && dist[i+k][j] < dist[i][j] + matrix[i+k][j]){
            dist[i+k][j] = dist[i][j] + matrix[i+k][j];
            dfs(i+k, j);
        }
        if (j + k < n && matrix[i][j] < matrix[i][j+k] && dist[i][j+k] < dist[i][j] + matrix[i][j+k]){
            dist[i][j+k] = dist[i][j] + matrix[i][j+k];
            dfs(i, j+k);
        }
        if (i - k >= 0 && matrix[i][j] < matrix[i-k][j] && dist[i-k][j] < dist[i][j] + matrix[i-k][j]){
            dist[i-k][j] = dist[i][j] + matrix[i-k][j];
            dfs(i-k, j);
        }
        if (j - k >= 0 && matrix[i][j] < matrix[i][j-k] && dist[i][j-k] < dist[i][j] + matrix[i][j-k]){
            dist[i][j-k] = dist[i][j] + matrix[i][j-k];
            dfs(i, j-k);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while(t--){
        cin >> n >> jump;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> matrix[i][j];
        dist.assign(n, vector<int>(n, -1));
        dist[0][0] = matrix[0][0];
        dfs(0, 0);
        int ans = -1;
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                ans = max(ans, dist[i][j]);
            }
        }
        cout << ans << '\n';
        if (t) cout << '\n';
    }
}
