#include<bits/stdc++.h>

int main(){
    int n, m;
    std::vector<std::vector<int>> pref2d(n + 1, std::vector<int>(m + 1, 0));
    std::vector<std::vector<int>> mat(n + 1, std::vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            pref2d[i][j] = pref2d[i][j - 1] + pref2d[i - 1][j] - pref2d[i - 1][j - 1] +mat[i - 1][j - 1];
            pref2d[i][j] = pref2d[i][j - 1] + pref2d[i - 1][j] - pref2d[i - 1][j - 1] + mat[i - 1][j - 1];
        }
    }
    auto query = [&](int x1, int y1, int x2, int y2){
        return pref2d[x2][y2] + pref2d[x1 - 1][y1 - 1] -
                pref2d[x1 - 1][y2] - pref2d[x2][y1 - 1];
    };
}