#include <bits/stdc++.h>

using namespace std;
#define isvalid(a_, b_, n_, m_) (a_ >= 0 && a_ < n_ && b_ >= 0 && b_ < m_)

const int maxn = 125, inf = 1e9;
vector<vector<int>> dist, paths;
vector<vector<bool>> matrix;
int ans, n, m, x[4] = {1, -1, 0, 0}, y[4] = {0, 0, 1, -1};

void bfs(int oi, int oj){
    queue<pair<int, int>> q;
    q.push({oi, oj});
    while(!q.empty()){
        int i = q.front().first, j = q.front().second;
        q.pop();
        for (int k = 0; k < 4; ++k){
            int ui = i + x[k], uj = j + y[k];
            if (isvalid(ui, uj, n, m) && matrix[ui][uj]){
                if (dist[ui][uj] == dist[i][j] + 1) paths[ui][uj] += paths[i][j];
                else if (dist[ui][uj] > dist[i][j] + 1){
                    paths[ui][uj] = paths[i][j];
                    dist[ui][uj] = dist[i][j] + 1;
                    q.push({ui, uj});
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int v, t; cin >> t;
    while(t--){
        cin >> n >> m;
        dist.assign(n, vector<int>(m, inf));
        paths.assign(n, vector<int>(m, 0));
        matrix.assign(n, vector<bool>(m, true));
        cin.ignore();
        for (int i = 0; i < n; ++i){
            string str;
            getline(cin, str);
            stringstream ss(str);
            ss >> str;
            v = stoi(str) - 1;
            while(ss >> str) matrix[v][stoi(str) - 1] = false;
        }
        dist[0][0] = 0;
        paths[0][0] = 1;
        bfs(0, 0);
        cout << paths[n-1][m-1] << '\n';
        if (t) cout << '\n';
    }
}
