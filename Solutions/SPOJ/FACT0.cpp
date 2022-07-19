#include <bits/stdc++.h>

using namespace std;

#define pi 3.141592653589793
#define eulerconstant 0.577215664901532
#define MAXN 100005
#define LGN 17
#define LSOne(S) ((int)(S) & -(int)(S))
#define f first
#define s second
#define inf (int)1e9
#define inf64 (int)4e18
#define goldenratio ((double)(1 + sqrt(5)) / 2)
#define isvalid(a_, b_, n_, m_) (a_ >= 0 && a_ < n_ && b_ >= 0 && b_ < m_)
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define rforn(i, n) for (int i = (int)(n); i >= 0; --i)
#define forr(i, l, r) for (int i = (int)(l); i < (int)(r); ++i)
#define rforr(i, l, r) for (int i = (int)(l); i >= (int)(r); --i)
#define Mid (l + ((r - l) >> 1))
#define GCD(a_, b_) (__gcd(a_, b_))
#define LCM(a_, b_) (a_/__gcd(a_, b_)*b_)
#define filIn freopen("input.txt", "r", (__acrt_iob_func(0)));
#define filOut freopen("output.txt", "w", (__acrt_iob_func(1)));

typedef pair<int, int> ii;
typedef pair<int, pair<int, int>> iii;
typedef pair<char, int> ci;
typedef pair<string, int> si;
typedef pair<int, string> is;
typedef vector< int > vi;
typedef vector< long > vl;
typedef vector< char > vc;
typedef vector<pair<int, int>> vii;
typedef vector<pair< int, pair<int, int>>> viii;
typedef vector<vector<int>> vvi;
typedef long long ll;
typedef int no;
typedef __uint128_t u128;

ll mult(ll a, ll b, ll m){
	return ((u128)a * b) % m;
}

ll FastExpo(ll x, ll b, ll p){
    ll ans = 1;
    x %= p;
    while(b){
        if (b & 1) ans = ((u128)ans * x) % p;
        x = ((u128)x * x) % p;
        b >>= 1;
    }
    return ans;
}

bool isPrime(ll x){
    if (x < 4) return x == 2 || x == 3;
    if (!(x & 1)) return false;
    ll d = x - 1;
    int r = __builtin_ctzll(d);
    d >>= r;
    ll bases[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    for (ll a : bases)
        if (a %= x){
            a = FastExpo(a, d, x);
            if (a == 1 || a == x - 1) continue;
            for(ll i = 1; i < r && 1 < a && a < x - 1; ++i){
                a = (a * a) % x;
            }
            if (a != x - 1) return false;
        }
    return true;
}

ll pollardRho(ll n){
	if (isPrime(n)) return n;
	if (!(n & 1)) return 2;
	srand (time(NULL));
	ll x, y, p, c;
	y = x = rand() % (n - 2) + 2;
	c = rand() % (n - 1) + 1;
	auto f = [&](ll xi){
		return ((u128)xi * xi + c) % n;
	};
	p = 1;
	while(p == 1){
		//cout << p << '\n';
		x = f(x);
		y = f(f(y));
		p = GCD(abs(x - y), n);
		if (p == n){
			y = x = rand() % (n - 2) + 2;
			c = rand() % (n - 1) + 1;
			p = 1;
		}
	}
	return p;
}

void solve(){
	ll n;
	while(cin >> n, n){
		map<ll, int> myHash;
		while(n > 1){
			ll fact = pollardRho(n);
			while(!isPrime(fact)){
				fact = pollardRho(fact);
			}
			myHash[fact]++;
			n /= fact;
		}
		for (auto it : myHash)
			cout << it.f << '^' << it.s << (it.f != myHash.rbegin()->f ? ' ' : '\n');
	}
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    solve();

    return 0;
}
