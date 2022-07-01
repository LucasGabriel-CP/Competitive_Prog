#include <bits/stdc++.h>

using namespace std;
#define isvalid(a_, b_, n_, m_) (a_ >= 0 && a_ < n_ && b_ >= 0 && b_ < m_)

const int maxn = 125, inf = 1e9, mod = 1000007;
vector<vector<long long>> paths;
char matrix[maxn][maxn];
int n;

void bfs(int oi, int oj){
    priority_queue<pair<int, int>> q;
    int ui, uj;
    q.push({oi, oj});
    while(!q.empty()){
        int i = q.top().first, j = q.top().second;
        q.pop();
        ui = i - 1; uj = j + 1;
        if (isvalid(ui, uj, n, n)){
            if (matrix[ui][uj] != 'B'){
                paths[ui][uj] = (paths[ui][uj] + paths[i][j]) % mod;
                if (matrix[ui][uj] == '.'){
                    matrix[ui][uj] = 'x';
                    q.push({ui, uj});
                }
            }
            else{
                ui = i - 2; uj = j + 2;
                if (isvalid(ui, uj, n, n) && matrix[ui][uj] != 'B'){
                    paths[ui][uj] = (paths[ui][uj] + paths[i][j]) % mod;
                    if (matrix[ui][uj] == '.'){
                        matrix[ui][uj] = 'x';
                        q.push({ui, uj});
                    }
                }
            }
        }
        ui = i - 1; uj = j - 1;
        if (isvalid(ui, uj, n, n)){
            if (matrix[ui][uj] != 'B'){
                paths[ui][uj] = (paths[ui][uj] + paths[i][j]) % mod;
                if (matrix[ui][uj] == '.'){
                    matrix[ui][uj] = 'x';
                    q.push({ui, uj});
                }
            }
            else{
                ui = i - 2; uj = j - 2;
                if (isvalid(ui, uj, n, n) && matrix[ui][uj] != 'B'){
                    paths[ui][uj] = (paths[ui][uj] + paths[i][j]) % mod;
                    if (matrix[ui][uj] == '.'){
                        matrix[ui][uj] = 'x';
                        q.push({ui, uj});
                    }
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int v, t; cin >> t;
    for (int c = 1; c <= t; ++c){
        cin >> n;
        paths.assign(n, vector<long long>(n, 0));
        int oi, oj;
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                cin >> matrix[i][j];
                if (matrix[i][j] == 'W'){ oi = i; oj = j; }
            }
        }
        paths[oi][oj] = 1;
        bfs(oi, oj);
        long long ans = 0;
        for (int i = 0; i < n; ++i)
            ans = (ans + paths[0][i]) % mod;
        cout << "Case " << c << ": " << ans << '\n';
    }
}
