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
typedef __int128 i128;

__int128 read() {
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

i128 mult(i128 a, i128 b, i128 m){
	return (a * b) % m;
}

i128 gcd(i128 a, i128 b){
    return (a % b ? gcd(b, a % b) : b);
}

i128 FastExpo(i128 x, i128 b, i128 p){
    i128 ans = 1;
    x %= p;
    while(b){
        if (b & 1) ans = (ans * x) % p;
        x = (x * x) % p;
        b >>= 1;
    }
    return ans;
}

bool isPrime(i128 x){
    if (x < 4) return x == 2 || x == 3;
    if (!(x & 1)) return false;
    i128 d = x - 1;
    int r = __builtin_ctzll(d);
    d >>= r;
    i128 bases[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    for (i128 a : bases)
        if (a %= x){
            a = FastExpo(a, d, x);
            if (a == 1 || a == x - 1) continue;
            for(i128 i = 1; i < r && 1 < a && a < x - 1; ++i){
                a = (a * a) % x;
            }
            if (a != x - 1) return false;
        }
    return true;
}

i128 pollardRho(i128 n){
	if (isPrime(n)) return n;
	if (!(n & 1)) return 2;
	srand (time(NULL));
	i128 x, y, p, c;
	y = x = rand() % (n - 2) + 2;
	c = rand() % (n - 1) + 1;
	auto f = [&](i128 xi){
		return (xi * xi + c) % n;
	};
	p = 1;
	while(p == 1){
		//cout << p << '\n';
		x = f(x);
		y = f(f(y));
		if (x > y)
    		p = gcd(x - y, n);
    	else
    	    p = gcd(y - x, n);
		if (p == n){
			y = x = rand() % (n - 2) + 2;
			c = rand() % (n - 1) + 1;
			p = 1;
		}
	}
	return p;
}

void solve(){
	i128 n = read();
	while(n){
		map<i128, int> myHash;
		while(n > 1){
			i128 fact = pollardRho(n);
			while(!isPrime(fact)){
				fact = pollardRho(fact);
			}
			myHash[fact]++;
			n /= fact;
		}
		for (pair<i128, int> it : myHash){
			print(it.f);
			printf("^%d%c", it.s, (it.f != myHash.rbegin()->f ? ' ' : '\n'));
		}
    	n = read();
	}
}

int main(){
    //ios_base::sync_with_stdio(false); cin.tie(0);
    solve();

    return 0;
}
