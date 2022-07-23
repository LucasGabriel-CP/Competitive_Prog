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

const int maxn = 4e2, inf = 1e9;

vector<int> heights, widths, dp;
int n;

int lis(int cur){
    if (cur == n) return 0;
    int &ans = dp[cur];
    if (ans != -1) return ans;
    ans = 0;
    for (int i = cur+1; i <= n; ++i){
        if (widths[i] != -1 && heights[i] > heights[cur])
            ans = max(ans, lis(i) + widths[i]);
    }
    return ans;
}

int lds(int cur){
    if (cur == n) return 0;
    int &ans = dp[cur];
    if (ans != -1) return ans;
    ans = 0;
    for (int i = cur+1; i <= n; ++i){
        if (widths[i] != -1 && heights[i] < heights[cur])
            ans = max(ans, lds(i) + widths[i]);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    filIn; filOut;
    cin >> t;
    for (int c = 1; c <= t; ++c){
        int val; cin >> n;
        heights.assign(n+1, -1);
        widths.assign(n+1, 0);
        for (int i = 1; i <= n; ++i){
            cin >>  heights[i];
        }
        for (int i = 1; i <= n; ++i){
            cin >> val;
            widths[i] = val > 0 ? val : -1;
        }
        dp.assign(n+2, -1);
        int inc = lis(0);
        dp.assign(n+2, -1);
        heights[0] = inf;
        int dec = lds(0);
        if (inc >= dec) cout << "Case " << c << ". Increasing (" << inc << "). Decreasing (" << dec << ").\n";
        else cout << "Case " << c << ". Decreasing (" << dec << "). Increasing (" << inc << ").\n";
    }
}
