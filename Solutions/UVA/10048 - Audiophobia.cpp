#include <bits/stdc++.h>

using namespace std;

#define pi 3.141592653589793
#define eulerconstant 0.577215664901532
#define MAXN 105
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

class UnionFind{
private:
    vi p, rank, setSize;
    int numSets;
public:
    vi parent;
    UnionFind(int N){
        p.assign(N, 0); for (int i = 0; i < N; ++i) p[i] = i;
        rank.assign(N, 0);
        setSize.assign(N, 1);
        numSets = N;
    }

    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    int numDS(){ return numSets; }
    int sizeOfSet(int i) { return setSize[findSet(i)]; }

    void unionSet(int i, int j){
        if (isSameSet(i, j)) return;
        int x = findSet(i), y = findSet(j);
        if (rank[x] > rank[y]){ swap(x, y); swap(i, j); }
        p[x] = y;
        if (rank[x] == rank[y]) ++rank[y];
        setSize[y] += setSize[x];
        --numSets;
    }
};

struct aresta{
    int a, b, p;
};

int a, b, n, s, q, dist[MAXN][MAXN];
vector<aresta> List;
vii AdjList[MAXN];
bool vis[MAXN];

void dfs(int ori, int dest, int u, int d = 0){
    dist[ori][u] = d;
    if (dist[ori][dest] != -1) return;
    vis[u] = true;
    for(ii v : AdjList[u]){
        if (!vis[v.f]){
            dfs(ori, dest, v.f, max(d, v.s));
        }
    }
}

void solve(){
    List.clear();
    forn(i, n){
        AdjList[i].clear();
        vis[i] = 0;
        forn(j, n)
            dist[i][j] = -1;
    }
    forn(i, s){
        aresta e; cin >> e.a >> e.b >> e.p;
        --e.a; --e.b;
        List.push_back(e);
    }

    sort(List.begin(), List.end(), [&](aresta i, aresta j){return i.p < j.p;});
    UnionFind UF(n);
    forn(i, s){
        if (!UF.isSameSet(List[i].a, List[i].b)){
            UF.unionSet(List[i].a, List[i].b);
            AdjList[List[i].a].push_back({List[i].b, List[i].p});
            AdjList[List[i].b].push_back({List[i].a, List[i].p});
        }
    }

    forn(i, q){
        memset(vis, 0, MAXN);
        cin >> a >> b;
        --a; --b;
        if (a > b) swap(a, b);
        dfs(a, b, a);
        if (dist[a][b] != -1) cout << dist[a][b] << '\n';
        else cout << "no path\n";
    }
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//filIn;	//filOut;
    int c = 0;
    while(cin >> n >> s >> q, n || s || q){
        if(c) cout << '\n';
        cout << "Case #" << ++c << '\n';
        solve();
    }

	return 0;
}
