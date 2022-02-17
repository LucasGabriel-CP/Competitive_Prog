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

int main(){
    ll B, P, M; //Base, Expoente, Mod
    while (scanf("%lld %lld %lld", &B, &P, &M) != EOF)
        printf("%lld\n", FastExpo(B, P, M));
}