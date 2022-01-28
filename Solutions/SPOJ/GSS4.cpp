#include <bits/stdc++.h>

using namespace std;

#define pi 3.141592653589793
#define eps 10e-9
#define eulerconstant 0.577215664901532
#define MAXN 100055
#define LGN 17
#define f first
#define s second
#define inf ~(1<<31)
#define inf64 1000000000000000000
#define goldenratio ((double)(1 + sqrt(5)) / 2)
#define isvalid(a_, b_, n_, m_) (a_ >= 0 && a_ < n_ && b_ >= 0 && b_ < m_)
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define rforn(i, n) for (int i = (int)(n); i >= 0; --i)
#define forr(i, l, r) for (int i = (int)(l); i < (int)(r); ++i)
#define rforr(i, l, r) for (int i = (int)(l); i >= (int)(r); --i)
#define Mid ((l + r) >> 1)
#define filIn freopen("input.txt", "r", stdin);
#define filOut freopen("output.txt", "w", stdout);

typedef pair<long long, long long> ii;
typedef pair<double, double> dd;
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
typedef long long no;

no BIT[MAXN], indx[MAXN];
int N, M;
ll A;

int nextId(int id){ return id == indx[id] ? id : indx[id] = nextId(indx[id]);}

void upd(int x, ll val){
    while(x <= N){
        BIT[x] += val;
        x += (x & -x);
    }
}

no query(int id){
    no Sum = 0;
    while(id){
        Sum += BIT[id];
        id -= (id & -id);
    }
    return Sum;
}

no query(int l, int r){
    return query(r) - (l == 1 ? 0 : query(l - 1));
}

void mudasqrt(int l, int r){
    for(int i = nextId(l); i <= r; i = nextId(i + 1)){
        no Val = query(i, i);
        no raiz = (no)(sqrt(Val));
        upd(i, raiz - Val);
        if (raiz == 1) indx[i] = nextId(i + 1);
    }
}

void solve(){
    int C = 1, x, y, t;
    while(cin >> N){
        forn(i, N + 2){
            BIT[i] = 0;
            indx[i] = i;
        }
        forn(i, N){
            cin >> A; upd(i + 1, A);
            if (A == 1) indx[i] = i + 1;
        }
        cin >> M;
        cout << "Case #" << C++ << ":\n";
        while(M--){
            cin >> t >> x >> y;
            if (x > y) swap(x, y);
            if (!t){
                mudasqrt(x, y);
            }else{
                cout << query(x, y) << '\n';
            }
        }
        cout << '\n';
    }
}

int main(){
    //filIn; filOut;
    ios_base::sync_with_stdio(false); cin.tie(0);
    solve();

    return 0;
}
