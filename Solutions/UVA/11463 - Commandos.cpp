#include <bits/stdc++.h>

using namespace std;

#define pi 3.141592653589793
#define eulerconstant 0.577215664901532
#define MAXN 105
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
#define filIn freopen("input.txt", "r", stdin);
#define filOut freopen("output.txt", "w", stdout);

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

int Matrix[MAXN][MAXN], n;

void floyd(){
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (Matrix[i][k] < inf && Matrix[k][j] < inf)
                    Matrix[i][j] = min(Matrix[i][j], Matrix[i][k] + Matrix[k][j]);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    //filIn; filOut;
    int t = 1;
    cin >> t;
    forn(c, t){
        int m; cin >> n >> m;
        forn(i, MAXN)
            forn(j, MAXN)
                Matrix[i][j] = (i == j ? 0 : inf);
        forn(i, m){
            int a, b; cin >> a >> b;
            Matrix[a][b] = 1;
            Matrix[b][a] = 1;
        }
        floyd();
        int o, d; cin >> o >> d;
        int ans = 0;
        forn(i, n){
            ans = max(Matrix[i][o] + Matrix[i][d], ans);
        }
        cout << "Case " << c + 1 << ": " << ans << '\n';
    }
    return 0;
}
