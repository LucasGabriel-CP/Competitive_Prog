#include <bits/stdc++.h>

using namespace std;

#define pi 3.141592653589793
#define eulerconstant 0.577215664901532
#define MAXN 205
#define LGN 15
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

struct Aresta{
    int a, b, p;
};

int n, m, Vet[MAXN];
vi Dist;
vector<Aresta> VetAresta;

void BellMan(int s = 0){
    Dist.assign(n, inf);
    Dist[s] = 0;
    forn(i, n - 1){
        forn(j, m){
            if (Dist[VetAresta[j].a] < inf)
                Dist[VetAresta[j].b] = min(Dist[VetAresta[j].b], Dist[VetAresta[j].a] + VetAresta[j].p);
        }
    }
    forn(i, n - 1){
        forn(j, m){
            if (Dist[VetAresta[j].a] < inf && Dist[VetAresta[j].b] > Dist[VetAresta[j].a] + VetAresta[j].p){
                Dist[VetAresta[j].b] = -inf;
            }
        }
    }
}

void solve(){
    VetAresta.clear();
    forn(i, n) cin >> Vet[i];
    cin >> m;
    forn(i, m){
        int a, b, p; cin >> a >> b;
        --a; --b;
        p = (Vet[b] - Vet[a]) * (Vet[b] - Vet[a]) * (Vet[b] - Vet[a]);
        VetAresta.push_back({a, b, p});
    }
    if (n) BellMan();
    int q; cin >> q;
    while(q--){
        int d; cin >> d;
        --d;
        if (Dist[d] < 3 || Dist[d] == inf)
            cout << "?\n";
        else
            cout << Dist[d] << '\n';
    }
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//filIn;	//filOut;
    int c = 1;
    while(cin >> n){
        cout << "Set #" << c++ << '\n';
        solve();
    }

	return 0;
}
