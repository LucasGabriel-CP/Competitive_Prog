#include <bits/stdc++.h>

#ifdef PIZZA
__attribute__((destructor))static void __destroy__(){std::cerr<<"\nElapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";}
#define sleep(x) std::this_thread::sleep_for(std::chrono::milliseconds(x))
#define filIn freopen("input.txt", "r", stdin); //(__acrt_iob_func(0))
#define filOut freopen("output.txt", "w", stdout); //(__acrt_iob_func(1))
#else
#define assert(x) void(0)
#define filIn void(0)
#define filOut void(0)
#define sleep(x) void(0)
#endif

#define pi 3.141592653589793
#define LSOne(S) ((int)(S) & -(int)(S))
#define f first
#define s second
#define goldenratio ((double)(1 + sqrt(5)) / 2)
#define isvalid(a_, b_, n_, m_) (a_ >= 0 && a_ < n_ && b_ >= 0 && b_ < m_)
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define rforn(i, n) for (int i = (int)(n); i >= 0; --i)
#define forr(i, l, r) for (int i = (int)(l); i < (int)(r); ++i)
#define rforr(i, l, r) for (int i = (int)(l); i >= (int)(r); --i)
#define fore(i, v) for (auto &i : v)
#define Mid (l + ((r - l) >> 1))
#define GCD(a_, b_) (__gcd(a_, b_))
#define LCM(a_, b_) ((a_/__gcd(a_, b_))*b_)
#define sz(vet) ((int)(vet).size())
#define all(vet) (vet).begin(),(vet).end()

using i64 = long long;

template<class T>inline int lb(const std::vector<T>&v,const T&x,int l=0,int r=-1){return(int)(lower_bound(v.begin()+l,(r==-1?v.end():v.begin()+r),x)-v.begin());}
template<class T>inline int ub(const std::vector<T>&v,const T&x,int l=0,int r=-1){return(int)(upper_bound(v.begin()+l,(r==-1?v.end():v.begin()+r),x)-v.begin());}
template<class T>inline int lb(const T*v,int n,const T&x,int l=0,int r=-1){return(int)(lower_bound(v+l,v+(r==-1?n:r),x)-v);}
template<class T>inline int ub(const T*v,int n,const T&x,int l=0,int r=-1){return(int)(upper_bound(v+l,v+(r==-1?n:r),x)-v);}

template<class T>T aabs(T a){return a<0?-a:a;}
template<class T,class T2>T mmin(T a,T2 b){return a<b?a:b;}
template<class T,class T2>T mmax(T a,T2 b){return a>b?a:b;}
template<class T,class ...T2>T mmin(T a,T2 ...b){return mmin(a,mmin(b...));}
template<class T,class ...T2>T mmax(T a,T2 ...b){return mmax(a,mmax(b...));}
#define abs aabs
#define min mmin
#define max mmax

typedef std::pair<int, int> ii;
typedef std::pair<char, int> ci;
typedef std::pair<std::string, int> si;
typedef std::pair<int, std::pair<int, int>> iii;
struct tri {
    int st, nd, rd;
    inline tri(): st(), nd(), rd() {}
    inline tri(int a, int b, int c): st(a), nd(b), rd(c) {}
    int cmp(const tri& t) {
        if (st != t.st) return st - t.st;
        if (nd != t.nd) return nd - t.nd;
        return rd - t.rd;
    }
    inline bool operator<(const tri& t) { return cmp(t) < 0; }
    inline bool operator==(const tri& t) { return cmp(t) == 0; }
};

typedef std::vector<int> vi;
typedef std::vector<long> vl;
typedef std::vector<char> vc;
typedef std::vector<std::pair<int, int>> vii;
typedef std::vector<std::pair<int, std::pair<int, int>>> viii;
typedef std::vector<std::vector<int>> vvi;

const int inf = (int)1e9;
const int inf64 = (int)4e18;
const int LGN = 17;
const int maxn = 100005;
const int mod = 1000000007;
const double eps = 1e-9;

void solve(){

}

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
    int tc = 1;
    std::cin >> tc;
    while(tc--){
        solve();
    }
    
    return 0;
}
