#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXN = 100010;
const int mod = 1e9+7;
ll fact[MAXN];

ll FastExpo(ll x, ll n, ll m) {
    x %= m;
    ll res = 1;
    while (n > 0) {
        if (n & 1)
            res = res * x % m;
        x = x * x % m;
        n >>= 1;
    }
    return res;
}

ll Fermat(ll a){
    return FastExpo(a, mod - 2, mod);
}

ll C(int n, int k){
    if (n < k) return 0;
    return (((fact[n] * Fermat(fact[k])) % mod) * Fermat(fact[n - k])) % mod;
}

int main(){
    fact[0] = 1;
    for(int i = 1; i < MAXN; ++i)
        fact[i] = (fact[i-1] * i) % mod;
    cout << C(100000, 50000) << '\n';

    return 0;
}
