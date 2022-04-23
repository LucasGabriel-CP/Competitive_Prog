#include <bits/stdc++.h>

using namespace std;

#define pi 3.141592653589793
#define eulerconstant 0.577215664901532
#define MAXN 200005
#define LGN 17
#define LSOne(S) ((int)(S) & -(int)(S))
#define f first
#define s second
#define inf 1e9
#define inf64 4e18
#define goldenratio ((double)(1 + sqrt(5)) / 2)
#define isvalid(a_, b_, n_, m_) (a_ >= 0 && a_ < n_ && b_ >= 0 && b_ < m_)
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define rforn(i, n) for (int i = (int)(n); i >= 0; --i)
#define forr(i, l, r) for (int i = (int)(l); i < (int)(r); ++i)
#define rforr(i, l, r) for (int i = (int)(l); i >= (int)(r); --i)
#define Mid (l + ((r - l) >> 1))
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

struct aresta{
	int a, b, p;
};
bool Comp(aresta a, aresta b) { return a.p < b.p; }

int pai[MAXN], Rank[MAXN];
vector< aresta > Lis;

int find_parent(int v){
    if (pai[v] == v)
        return v;
    return pai[v] = find_parent(pai[v]);
}

void unir(int u, int v){
    int x = find_parent(u);
    int y = find_parent(v);
    if (Rank[x] > Rank[y]){
        ++Rank[x];
        pai[y] = x;
    }
    else{
        ++Rank[y];
        pai[x] = y;
    }
}

void solve(){
    int N, M;
    aresta Edge;
    while(cin >> M >> N, N || M){
        ll Tot, Ans;
        Ans = Tot = 0;
        forn(i, M){
            pai[i] = i;
            Rank[i] = 1;
        }
        forn(i, N){
            cin >> Edge.a >> Edge.b >> Edge.p;
            Lis.push_back(Edge);
            Tot += Edge.p;
        }
        sort(Lis.begin(), Lis.end(), Comp);
        forn(i, N){
            int x, y, p;
            x = Lis[i].a; y = Lis[i].b; p = Lis[i].p;
            if (find_parent(x) != find_parent(y)){
                Ans += p;
                unir(x, y);
            }
        }
        cout << Tot - Ans << '\n';
        Lis.clear();
    }
}

int main(){
    //filIn; //filOut;
    ios_base::sync_with_stdio(false); cin.tie(0);
    solve();

    return 0;
}
