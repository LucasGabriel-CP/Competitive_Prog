#include <bits/stdc++.h>

using i64 = long long;

constexpr int mod = 998244353;
// assume -mod <= x < 2mod
int norm(int x) {
    if (x < 0) {
        x += mod;
    }
    if (x >= mod) {
        x -= mod;
    }
    return x;
}

template<class T>
T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}

struct Mint {
    int x;
    Mint(int x = 0) : x(norm(x)) {}
    Mint(i64 x) : x(norm(x % mod)) {}
    int val() const {
        return x;
    }
    Mint operator-() const {
        return Mint(norm(mod - x));
    }
    Mint inv() const {
        assert(x != 0);
        return power(*this, mod - 2);
    }
    Mint &operator*=(const Mint &rhs) {
        x = i64(x) * rhs.x % mod;
        return *this;
    }
    Mint &operator+=(const Mint &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    Mint &operator-=(const Mint &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    Mint &operator/=(const Mint &rhs) {
        return *this *= rhs.inv();
    }
    friend Mint operator*(const Mint &lhs, const Mint &rhs) {
        Mint res = lhs;
        res *= rhs;
        return res;
    }
    friend Mint operator+(const Mint &lhs, const Mint &rhs) {
        Mint res = lhs;
        res += rhs;
        return res;
    }
    friend Mint operator-(const Mint &lhs, const Mint &rhs) {
        Mint res = lhs;
        res -= rhs;
        return res;
    }
    friend Mint operator/(const Mint &lhs, const Mint &rhs) {
        Mint res = lhs;
        res /= rhs;
        return res;
    }
    friend std::istream &operator>>(std::istream &is, Mint &a) {
        i64 v;
        is >> v;
        a = Mint(v);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const Mint &a) {
        return os << a.val();
    }
};

Mint Fermat(Mint a){
    return power(a, mod - 2);
}

const int maxn = (int)1e5;
Mint fact[maxn];

Mint C(int n, int k){
    if (n < k) return 0;
    return (fact[n] * fact[k].inv()) * fact[n - k].inv();
}

int main(){
    fact[0] = 1;
    for(int i = 1; i < maxn; ++i)
        fact[i] = fact[i-1] * i;


}
