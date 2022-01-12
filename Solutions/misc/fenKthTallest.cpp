#include <bits/stdc++.h>

using namespace std;

#define pi 3.141592653589793
#define eulerconstant 0.577215664901532
#define MAXN 1000005
#define LGN 17
#define f first
#define s second
#define inf ~(1<<31)
#define inf64 1000000000000000000
#define goldenratio ((double)(1 + sqrt(5)) / 2)
#define isvalid(a_, b_, n_, m_) (a_ >= 0 && a_ < n_ && b_ >= 0 && b_ < m_)
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define rfor(i, n) for (int i = (n); i >= 0; --i)
#define forlr(i, l, r) for (int i = (int)(l); i < (int)(r); ++i)
#define Mid ((l + r) >> 1)
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
typedef long long no;

no BIT[MAXN];
int N, Vet[MAXN];

int MSB(int x){
    x = (int)(log2(x));
    return (1 << x);
}

void upd(int id, int val){
    while(id <= N){
        BIT[id] += val;
        id += (id & -id);
    }
}

void build(){
    memset(BIT, 0, MAXN);
    forn(i, N){
        upd(i + 1, Vet[i]);
    }
}

int query(int k){
    int id = 0, bitMask = MSB(N);
    while(bitMask){
        bitMask >>= 1;
        int tMid = id + bitMask;
        if (tMid > N) continue;
        if (k > BIT[tMid]){
            id += bitMask;
            k -= BIT[tMid];
        }
        cout << "bitMask: " << bitMask
            << " tMid: " << tMid
            << " id: " << id
            << " Soma: " << Soma << '\n';
    }
    return id + 1;
}

int main(){
    N = 16;
    //8 2 10 100 1 2
    memset(BIT, 0, N);
    forn(i, 6){
        cin >> Vet[i];
        upd(i + 1, Vet[i]);
    }
    forn(i, N) cout << BIT[i] << ' ';
    cout << BIT[N] << '\n';
    int k;
    while(cin >> k) cout << query(k) << '\n';
    return 0;
}
