#include <bits/stdc++.h>

#ifdef PIZZA
__attribute__((destructor))static void __destroy__(){std::cerr<<"\nElapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";}
#endif

using namespace std;

long long pd[100][3];

long long f(int cur, int n, bool past){
    if (cur >= n) return pd[cur][past] = 1;
    if (pd[cur][past] != -1) return pd[cur][past];
    if (past || cur == 1) return pd[cur][past] = f(cur+1, n, false);
    return pd[cur][past] = f(cur+1, n, true) + f(cur+1, n, false);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    while(cin >> n, n){
        for (int i = 0; i < 100; ++i)
            pd[i][0] = pd[i][1] = -1;
        cout << f(1, n, false) << '\n';
    }

    return 0;
}
