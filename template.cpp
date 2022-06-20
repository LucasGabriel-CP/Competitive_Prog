#include <bits/stdc++.h>

using namespace std;

#define pi 3.141592653589793
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
#define sz(vet) ((int)(vet).size())
#define all(vet) (vet).begin(),(vet).end()

typedef pair<int, int> ii;
typedef pair<int, pair<int, int>> iii;
typedef pair<char, int> ci;
typedef pair<string, int> si;
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<char> vc;
typedef vector<pair<int, int>> vii;
typedef vector<pair< int, pair<int, int>>> viii;
typedef vector<vector<int>> vvi;
typedef long long ll;
typedef int no;

template<class T,class T2>T mmin(T a,T2 b){return a<b?a:b;}
template<class T,class T2>T mmax(T a,T2 b){return a>b?a:b;}
template<class T,class ...T2>T mmin(T a,T2 ...b){return mmin(a,mmin(b...));}
template<class T,class ...T2>T mmax(T a,T2 ...b){return mmax(a,mmax(b...));}
template<class T>T aabs(T a){return a<0?-a:a;}

#define min mmin
#define max mmax
#define abs aabs

void solve(){

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
        solve();

    return 0;
}
