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

i64 Comb(int n, int k){
    if (n < k) return 0;
    return (((fact[n] * Fermat(fact[k])) % mod) * Fermat(fact[n - k])) % mod;
}

i64 stars_and_bars(int n, int k){
    return Comb(n + k - 1, n);
}

int main(){
    fact[0] = 1;
    for(int i = 1; i < maxn; ++i)
        fact[i] = (fact[i-1] * i) % mod;
    //Cal Comb(n, k)


    //O(n^2)
    const int maxn = (int)1e3;
    int C[maxn + 1][maxn + 1];
    C[0][0] = 1;
    for (int n = 1; n <= maxn; ++n) {
        C[n][0] = C[n][n] = 1;
        for (int k = 1; k < n; ++k)
            C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
    }

    return 0;
}
