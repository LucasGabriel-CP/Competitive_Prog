#include <bits/stdc++.h>

using namespace std;

#define pi 3.141592653589793
#define eulerconstant 0.577215664901532
#define MAXN 10005
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

const int val = 1e5 + 5;
int n, q, coins[MAXN];
bitset<val> valid;
list<int> all_cc;

struct Querie{
    int L, R, idx;
};
Querie queries[5 * val];

void cc(){
    valid.reset();
    valid[0] = 1;
    forn(i, n){
        valid |= valid << coins[i];
    }
}

int ans[5 * val];
int BIT[5 * val + 500];

void upd(int id, int x){
    while(id <= val){
        BIT[id] += x;
        id += LSOne(id);
    }
}

int qry(int id){
    int sum = 0;
    while(id){
        sum += BIT[id];
        id -= LSOne(id);
    }
    return sum;
}

void solve(){
    scanf("%d %d", &n, &q);
    memset(BIT, 0, sizeof(BIT));
    forn(i, n) cin >> coins[i];
    forn(i, q){
        ans[i] = 0;
        scanf("%d %d", &queries[i].L, &queries[i].R);
        queries[i].idx = i;
    }
    sort(queries, queries + q, [&](Querie a, Querie b){
            if (a.L != b.L) return a.L < b.L;
            return a.R < b.R;
         });
    cc();
    forn(i, val) upd(i + 1, valid[i + 1]);
    int k = 0;
    forn(i, q){
        ans[queries[i].idx] = qry(queries[i].R) - qry(queries[i].L - 1);
    }
    forn(i, q){
        printf("%d\n", ans[i]);
    }
}

int main(){
   // ios_base::sync_with_stdio(false); cin.tie(0);
    solve();

    return 0;
}
