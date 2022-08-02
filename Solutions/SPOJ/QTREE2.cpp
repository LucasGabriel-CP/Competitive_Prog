#include <bits/stdc++.h>

using namespace std;

#define pi 3.141592653589793
#define eulerconstant 0.577215664901532
#define MAXN 10005
#define LGN 15
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

int n, m, depth[MAXN], parent[MAXN][LGN];
ll Dist[MAXN][LGN];
vii AdjList[MAXN];

void dfs(int u){
    for(ii v : AdjList[u]){
        if (v.f == parent[u][0]) continue;
        parent[v.f][0] = u;
        Dist[v.f][0] = v.s;
        depth[v.f] = depth[u] + 1;
        dfs(v.f);
    }
}

pair<ll, int> LCA(int u, int v){
    if (depth[u] > depth[v]) swap(u, v);
    int d = depth[v] - depth[u];
    ll ans = 0;
    forn(i, LGN){
        if (d & (1<<i)){
            ans += Dist[v][i];
            v = parent[v][i];
        }
    }
    if (u == v) return {ans, u};
    rforn(i, LGN - 1){
        if (parent[u][i] != parent[v][i]){
            ans += Dist[u][i];
            ans += Dist[v][i];
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return {ans + Dist[u][0] + Dist[v][0], parent[u][0]};
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//filIn; //filOut;
	int Case; cin >> Case;
    int a, b, p, k;
	forn(c, Case){
        cin >> n;
        forn(i, n){
            parent[i][0] = i;
            AdjList[i].clear();
        }
        forn(i, n - 1){
            cin >> a >> b >> p;
            --a; --b;
            AdjList[a].push_back({b, p});
            AdjList[b].push_back({a, p});
        }
        int root = 0;
        depth[root] = 0;
        dfs(0);
        forr(i, 1, LGN){
            forn(j, n){
                parent[j][i] = parent[parent[j][i-1]][i-1];
                Dist[j][i] = Dist[j][i - 1] + Dist[parent[j][i-1]][i-1];
            }
        }

        string Q; cin >> Q;
        pair<ll, int> ans;
        while(Q != "DONE"){
            cin >> a >> b;
            --a; --b;
            //if (depth[a] > depth[b]) swap(a, b);
            ans = LCA(a, b);
            if (Q[1] == 'I'){
                cout << ans.f << '\n';
            }
            else{
                cin >> k;
                if (k > depth[a] - depth[ans.s]){
					k -= (depth[a] - depth[ans.s] + 1);
					k = (depth[b] - depth[ans.s]) - k;
					a = b;
				}
				else --k;
				int kth = a;
				forn(i, LGN-1){
					if (k & (1<<i)){
						kth = parent[kth][i];
					}
				}
				cout << kth + 1 << '\n';
            }
            cin >> Q;
        }

	}

	return 0;
}
