#include <bits/stdc++.h>

using namespace std;

#ifdef PIZZA
__attribute__((destructor))static void __destroy__(){std::cerr<<"\nElapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";}
#define sleep(x) this_thread::sleep_for(chrono::milliseconds(x))
#define filIn freopen("input.txt", "r", stdin); //(__acrt_iob_func(0))
#define filOut freopen("output.txt", "w", stdout); //(__acrt_iob_func(1))
#else
#define assert(x) void(0)
#define filIn void(0)
#define filOut void(0)
#define sleep(x) void(0)
#endif

const int maxn = 5*1e3 + 5, inf = 1e9;
const long long inf64 = 1e18;
vector<long long> molds;
long long cost[maxn][maxn], dp[maxn][maxn];
int n, k;

void computeCost(){
    for (int i = 0; i <= n; ++i)
        cost[i][i] = 0;
    for (int i = 0; i < n; ++i)
        for (int j = i-1; j >= 0; --j)
            cost[j][i] = cost[j+1][i] + (molds[i]^molds[j]);
    for (int i = 0; i < n; ++i)
        for (int j = 1; j < n; ++j)
            cost[i][j] += cost[i][j-1];
}

void DnC(int c, int l, int r, int il, int ir){
    if (l > r) return;
    int j = (l+r)/2, k = -1;
    dp[c][j] = inf64;
    for (int i = max(c, il); i <= min(ir, j); ++i){
        if  (!i){ k = i; continue; }
        long long temp = dp[c-1][i-1] + cost[i][j];
        if (temp < dp[c][j]){
            dp[c][j] = temp;
            k = i;
        }
    }
    DnC(c, l, j-1, il, k);
    DnC(c, j+1, r, k, ir);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    filIn; filOut;
    cin >> n >> k;
    molds.resize(n);
    for (long long &i: molds) cin >> i;
    computeCost();
    for (int i = 0; i <= n; i++) dp[0][i] = cost[0][i];
    for (int c = 1; c <= k; c++)
        DnC(c, 0, n-1, 0, n-1);
    cout << dp[k][n-1] << '\n';
}
