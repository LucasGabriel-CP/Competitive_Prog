using i64 = long long;


template<class T>
T power(T x, i64 n) {
    T res = 1;
    while (n) {
        if (n & 1)
            res = res * x;
        x = x * x;
        n >>= 1;
    }
    return res;
}

// assume -mod <= x < 2mod
template<int P>
struct Mint {
    int x;
    constexpr Mint() : x{} {}
    constexpr Mint(i64 x) : x{norm(x % getMod())} {}
    
    static int Mod;
    constexpr static int getMod() {
        if (P > 0) {
            return P;
        } else {
            return Mod;
        }
    }
    constexpr static void setMod(int Mod_) {
        Mod = Mod_;
    }
    constexpr int norm(int x) const {
        if (x < 0) {
            x += getMod();
        }
        if (x >= getMod()) {
            x -= getMod();
        }
        return x;
    }
    constexpr int val() const {
        return x;
    }
    explicit constexpr operator int() const {
        return x;
    }
    constexpr Mint operator-() const {
        Mint res;
        res.x = norm(getMod() - x);
        return res;
    }
    constexpr Mint inv() const {
        assert(x != 0);
        return power(*this, getMod() - 2);
    }
    constexpr Mint &operator*=(Mint rhs) & {
        x = 1LL * x * rhs.x % getMod();
        return *this;
    }
    constexpr Mint &operator+=(Mint rhs) & {
        x = norm(x + rhs.x);
        return *this;
    }
    constexpr Mint &operator-=(Mint rhs) & {
        x = norm(x - rhs.x);
        return *this;
    }
    constexpr Mint &operator/=(Mint rhs) & {
        return *this *= rhs.inv();
    }
    friend constexpr Mint operator*(Mint lhs, Mint rhs) {
        Mint res = lhs;
        res *= rhs;
        return res;
    }
    friend constexpr Mint operator+(Mint lhs, Mint rhs) {
        Mint res = lhs;
        res += rhs;
        return res;
    }
    friend constexpr Mint operator-(Mint lhs, Mint rhs) {
        Mint res = lhs;
        res -= rhs;
        return res;
    }
    friend constexpr Mint operator/(Mint lhs, Mint rhs) {
        Mint res = lhs;
        res /= rhs;
        return res;
    }
    friend constexpr std::istream &operator>>(std::istream &is, Mint &a) {
        i64 v;
        is >> v;
        a = Mint(v);
        return is;
    }
    friend constexpr std::ostream &operator<<(std::ostream &os, const Mint &a) {
        return os << a.val();
    }
    friend constexpr bool operator==(Mint lhs, Mint rhs) {
        return lhs.val() == rhs.val();
    }
    friend constexpr bool operator!=(Mint lhs, Mint rhs) {
        return lhs.val() != rhs.val();
    }
};

constexpr int mod = 998244353;
using U = Mint<mod>;

template<i64 P>
struct Mlong {
    i64 x;
    constexpr Mlong() : x{} {}
    constexpr Mlong(i64 x) : x{norm(x % getMod())} {}
    
    static i64 Mod;
    constexpr static i64 getMod() {
        if (P > 0) {
            return P;
        } else {
            return Mod;
        }
    }
    constexpr static void setMod(i64 Mod_) {
        Mod = Mod_;
    }
    constexpr i64 norm(i64 x) const {
        if (x < 0) {
            x += getMod();
        }
        if (x >= getMod()) {
            x -= getMod();
        }
        return x;
    }
    constexpr i64 val() const {
        return x;
    }
    explicit constexpr operator i64() const {
        return x;
    }
    constexpr Mlong operator-() const {
        Mlong res;
        res.x = norm(getMod() - x);
        return res;
    }
    constexpr Mlong inv() const {
        assert(x != 0);
        return power(*this, getMod() - 2);
    }
    constexpr Mlong &operator*=(Mlong rhs) & {
        x = 1LL * x * rhs.x % getMod();
        return *this;
    }
    constexpr Mlong &operator+=(Mlong rhs) & {
        x = norm(x + rhs.x);
        return *this;
    }
    constexpr Mlong &operator-=(Mlong rhs) & {
        x = norm(x - rhs.x);
        return *this;
    }
    constexpr Mlong &operator/=(Mlong rhs) & {
        return *this *= rhs.inv();
    }
    friend constexpr Mlong operator*(Mlong lhs, Mlong rhs) {
        Mlong res = lhs;
        res *= rhs;
        return res;
    }
    friend constexpr Mlong operator+(Mlong lhs, Mlong rhs) {
        Mlong res = lhs;
        res += rhs;
        return res;
    }
    friend constexpr Mlong operator-(Mlong lhs, Mlong rhs) {
        Mlong res = lhs;
        res -= rhs;
        return res;
    }
    friend constexpr Mlong operator/(Mlong lhs, Mlong rhs) {
        Mlong res = lhs;
        res /= rhs;
        return res;
    }
    friend constexpr std::istream &operator>>(std::istream &is, Mlong &a) {
        i64 v;
        is >> v;
        a = Mlong(v);
        return is;
    }
    friend constexpr std::ostream &operator<<(std::ostream &os, const Mlong &a) {
        return os << a.val();
    }
    friend constexpr bool operator==(Mlong lhs, Mlong rhs) {
        return lhs.val() == rhs.val();
    }
    friend constexpr bool operator!=(Mlong lhs, Mlong rhs) {
        return lhs.val() != rhs.val();
    }
};

const int maxn = (int)1e5;
U fact[maxn];

U C(int n, int k){
    if (n < k) return 0;
    return (fact[n] * fact[k].inv()) * fact[n - k].inv();
}

int main(){

}
