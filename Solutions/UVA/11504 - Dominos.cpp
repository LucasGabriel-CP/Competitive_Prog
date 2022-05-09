#include <bits/stdc++.h>

using namespace std;

#define pi 3.141592653589793
#define eulerconstant 0.577215664901532
#define MAXN 100005
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
typedef unsigned long long ll;
typedef int no;

int n, m;
vi AdjList[MAXN], ReAdj[MAXN], Ord;
bool vis[MAXN];

void dfs(int u){
    vis[u] = true;
    for (int v : AdjList[u])
        if(!vis[v]) dfs(v);
    Ord.push_back(u);
}

void dfs2(int u){
    vis[u] = true;
    for (int v : AdjList[u])
        if(!vis[v]) dfs2(v);
}

void solve(){
    forn(i, n){
        vis[i] = false;
        AdjList[i].clear();
    }
    Ord.clear();
    cin >> n >> m;
    while(m--){
        int a, b; cin >> a >> b;
        --a; --b;
        AdjList[a].push_back(b);
    }
    int ans = 0;
    forn(i, n)
        if(!vis[i]){ dfs(i); }
    memset(vis, false, n + 1);
    reverse(Ord.begin(), Ord.end());
    for (int i : Ord){
        if(!vis[i]){
            dfs2(i); ++ans;
        }
    }
    cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//filIn; //filOut;
	int Case; cin >> Case;
	forn(i, Case){
        solve();
	}

	return 0;
}
