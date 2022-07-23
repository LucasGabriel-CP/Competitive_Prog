#include <bits/stdc++.h>

#ifdef PIZZA
__attribute__((destructor))static void __destroy__(){std::cerr<<"\nElapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";}
#define debug(x...) cerr<<"\x1b[91m"<<__LINE__<<" ["#x"] =",debug(x),cerr<<"\x1b[0m\n"
#define sleep(x) this_thread::sleep_for(chrono::milliseconds(x))
#define filIn freopen("input.txt", "r", stdin); //(__acrt_iob_func(0))
#define filOut freopen("output.txt", "w", stdout); //(__acrt_iob_func(1))
#else
#define assert(x) void(0)
#define filIn void(0)
#define filOut void(0)
#define sleep(x) void(0)
#endif

using namespace std;
const int maxn = 1e2+50, inf = 1e9;

int vet[maxn], dp[maxn][maxn], opt[maxn][maxn], sum[maxn];

int cut(int n){
    for (int i = 0; i < n-1; ++i){
        dp[i][i+1] = 0;
    }
    //otimização possível por causa de Knuth-Yao
    for (int len = 2; len < n; ++len){
        for (int i = 0; i < n - len; ++i){
            int j = i + len;
            dp[i][j] = inf;
            for (int k = i; k < j; ++k){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + (vet[j] - vet[i]));
            }
        }
    }
    return dp[0][n-1];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    filIn; filOut;
    int t, l, n;
    while(cin >> l, l){
        cin >> n;
        vet[0] = 0;
        vet[n+1] = l;
        for (int i = 1; i <= n; ++i) cin >> vet[i];
        cout << "The minimum cutting is " << cut(n+2) << ".\n";
    }
    return 0;
}
