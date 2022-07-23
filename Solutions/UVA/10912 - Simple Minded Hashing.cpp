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

const int maxn = 4e2;

int l, dp[30][maxn][30];

int f(int cur, int s, int id){
    if (cur == l) return (s == 0 ? 1 : 0);
    if (s - id < 0 || id > 26) return 0;
    if (dp[cur][s][id] != -1) return dp[cur][s][id];
    int ans = 0;
    for (int i = id; i <= 26; ++i){
        ans += f(cur+1, s-i, i+1);
    }
    return dp[cur][s][id] = ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int s, t = 1;
    filIn; filOut;
    while(cin >> l >> s, l && s){
        memset(dp, -1, sizeof(dp));
        int ans = (l > 26 || s > 351 ? 0 : f(0, s, 1));
        cout << "Case " << t++ << ": " << ans << '\n';
    }
}
