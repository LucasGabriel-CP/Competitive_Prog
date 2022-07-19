#include <bits/stdc++.h>

using namespace std;

#define pi 3.141592653589793
#define eulerconstant 0.577215664901532
#define MAXN 30005
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

struct Querie{
    int L, R, idx;
};
Querie queries[200000];

int At, bs, n, q, vet[MAXN], ans[200000];

unordered_map<int, int> myHash;

void add(int k){
    myHash[vet[k]]++;
    if (myHash[vet[k]] == 1) ++At;
}

void rmv(int k){
    myHash[vet[k]]--;
    if (!myHash[vet[k]]) --At;
}

void solve(){
    cin >> n;
    forn(i, n) cin >> vet[i];
    bs = sqrt(n);
    cin >> q;
    forn(i, q){
        cin >> queries[i].L >> queries[i].R;
        --queries[i].L;
        --queries[i].R;

        queries[i].idx = i;
    }
    sort(queries, queries + q, [&](Querie a, Querie b){
            int ba = a.L/bs;
            int bb = b.L/bs;
            if (ba == bb) return (ba % 2 & 1 ? a.R < b.R : a.R > b.R);
            return ba < bb;
         });
    int mol, mor = -1;
    mol = At = 0;
    forn(k, q){
        while(mor < queries[k].R) add(++mor);
        while(mor > queries[k].R) rmv(mor--);
        while(mol < queries[k].L) rmv(mol++);
        while(mol > queries[k].L) add(--mol);
        ans[queries[k].idx] = At;
    }
    forn(i, q) cout << ans[i] << '\n';

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    solve();

    return 0;
}
