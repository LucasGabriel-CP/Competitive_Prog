#include <iostream>

const int maxn = 5005, inf = 1000000000;
int cost[maxn][maxn], dp[maxn][maxn], heights[maxn];

void DnC(int c, int l, int r, int il, int ir){
    if (l > r) return;
    int j = (l+r)>>1, best_i = -1;
    int &best = dp[c][j];
    best = inf;
    int mn = (ir > j ? j : ir), mx = (il > c ? il : c), temp;
    for (int i = mx; i <= mn; ++i){
        if  (!i){ best_i = i; continue; }
        temp = dp[c-1][i-1] + cost[i][j];
        if (temp < best){
            best = temp;
            best_i = i;
        }
    }
    DnC(c, l, j-1, il, best_i);
    DnC(c, j+1, r, best_i, ir);
}

int main(){
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
    int n, k; std::cin >> n >> k;
    for (int i = 0; i < n; i++) std::cin >> heights[i];

    for (int i = 0; i < n; ++i){
        cost[i][i] = 0;
        for (int j = i+1; j < n; j++)
            cost[i][j] = cost[i][j-1] + (heights[i] > heights[j]);
    }
    for (int i = n-2; i >= 0; --i)
        for (int j = i; j < n; ++j)
            cost[i][j] += cost[i+1][j];

    for (int i = 0; i < n; i++) dp[0][i] = cost[0][i];
    for (int c = 1; c < k; c++)
        DnC(c, 0, n-1, 0, n-1);
    std::cout << dp[k-1][n-1] << '\n';
}
