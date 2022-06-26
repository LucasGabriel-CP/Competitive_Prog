#include <bits/stdc++.h>

using namespace std;

#define isvalid(a_, b_, n_, m_) (a_ >= 0 && a_ < n_ && b_ >= 0 && b_ < m_)

char matrix[10][10];
int x[4] = {1, -1, 0, 0}, y[4] = {0, 0, 1, -1};
const int inf = (int)1e9;

int bfs(int oi, int oj, char tipo){
    queue<pair<int, int>> q;
    q.push({oi, oj});
    int ans = 1;
    matrix[oi][oj] = tipo;
    while(!q.empty()){
        pair<int, int> u = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i){
            int vi = u.first + x[i], vj = u.second + y[i];
            if (isvalid(vi, vj, 9, 9)){
                if (matrix[vi][vj] == '.'){
                    ++ans; matrix[vi][vj] = tipo;
                    q.push({vi, vj});
                }
                else if (matrix[vi][vj] != tipo) ans = -inf;
            }
        }
    }
    return ans < 0 ? 0 : ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    for(int c = 1; c <= t; ++c){
        int w = 0, b = 0;
        for (int i = 0; i < 9; ++i){
            for (int j = 0; j < 9; ++j){
                cin >> matrix[i][j];
                if (matrix[i][j] == 'X') ++b;
                else if (matrix[i][j] == 'O') ++w;
            }
        }
        for (int i = 0; i < 9; ++i){
            for (int j = 0; j < 9; ++j){
                if (matrix[i][j] == '.'){
                    for (int k = 0; k < 4; ++k){
                        int ui = i + x[k], uj = j + y[k];
                        if (isvalid(ui, uj, 9, 9)){
                            if (matrix[ui][uj] == 'X'){ b += bfs(i, j, 'X'); break; }
                            else if (matrix[ui][uj] == 'O'){ w += bfs(i, j, 'O'); break; }
                        }
                    }
                }
            }
        }
        cout << "Black " << b << " White " << w << '\n';
    }

	return 0;
}
