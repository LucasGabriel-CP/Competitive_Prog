#include <bits/stdc++.h>

using i64 = long long;
const int maxn = 100010, mod = 1e9+7;
i64 fact[maxn];

i64 FastExpo(i64 x, i64 n, i64 m) {
    x %= m;
    i64 res = 1;
    while (n) {
        if (n & 1)
            res = res * x % m;
        x = x * x % m;
        n >>= 1;
    }
    return res;
}

i64 Fermat(i64 a){
    return FastExpo(a, mod - 2, mod);
}

i64 C(int n, int k){
    if (n < k) return 0;
    return (((fact[n] * Fermat(fact[k])) % mod) * Fermat(fact[n - k])) % mod;
}

int main(){
    fact[0] = 1;
    for(int i = 1; i < maxn; ++i)
        fact[i] = (fact[i-1] * i) % mod;

    std::cout << C(100000, 50000) << '\n';

    return 0;
}
