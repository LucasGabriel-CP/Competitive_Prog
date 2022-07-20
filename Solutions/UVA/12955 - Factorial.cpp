//Da pra fazer guloso tbm
#include <bits/stdc++.h>

#ifdef PIZZA
__attribute__((destructor))static void __destroy__(){std::cerr<<"\nElapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";}
#endif

using namespace std;

const int maxn = 1e5+50, inf = 1e9;
int fact[11];
int pd[11][maxn];

int f(int cur, int tot, int n){
    if (cur > 10 || tot > n) return inf;
    if (tot == n) return 0;
    if (pd[cur][tot] != -1) return pd[cur][tot];
    if (tot + fact[cur] > n) return pd[cur][tot] = f(cur+1, tot, n);
    return pd[cur][tot] = min(f(cur+1, tot+fact[cur], n), 1 + f(cur, tot+fact[cur], n));
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    fact[0] = 1;
    for (int i = 1; i <= 10; ++i) fact[i] = i * fact[i-1];
    sort(fact, fact + 11, greater<int>());
    while(cin >> n){
        for (int i = 0; i < 11; ++i)
            for (int j = 0; j <= n; ++j)
                pd[i][j] = -1;
        cout << f(0, 0, n) << '\n';
    }

    return 0;
}
