#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100005
#define MAXLOGN 10
#define f first
#define s second

typedef pair<int, int> ii;
typedef vector< int > vi;
typedef vector<pair<int, int>> vii;
typedef long long ll;

int N, Q, S, T, P[MAX_N][MAXLOGN], level[MAX_N];
ll Dist[MAX_N][MAXLOGN];

vector<vii> AdjList;

void dfs(int u) {
    for(auto v : AdjList[u]) {
        if(v.f == P[u][0]) continue;
        P[v.f][0] = u;
        Dist[v.f][0] = v.s;
        level[v.f] = level[u] + 1;
        dfs(v.f);
    }
}

void computeParent(int raiz) {
    level[raiz] = 0;
    P[raiz][0] = raiz; Dist[raiz][0] = 0;
    dfs(raiz);

    for(int j = 1; j < MAXLOGN; j++){
        for(int i = 1; i <= N; i++){
            P[i][j] = P[P[i][j-1]][j-1];
            Dist[i][j] = Dist[i][j - 1] + Dist[P[i][j-1]][j-1];
        }
    }
}

ll LCA(int u, int v) {
    if(level[u] > level[v]) swap(u, v);
    int d = level[v] - level[u];
    ll Ans = 0;
    // Sobe v em O(log n) até ficar na mesma altura de u
    for(int i = 0; i < MAXLOGN; i++){
        if(d & (1 << i)) {
            Ans += Dist[v][i];
            v = P[v][i];
        }
    }

    // Aqui estão na mesma altura
    if(u == v){
        return Ans;
    }else{
        // Sobe os dois nodos ao mesmo tempo até encontrarem o menor ancestral comumm
        for(int i = MAXLOGN-1; i >= 0; i--){
            while(P[u][i] != P[v][i]){
                Ans += Dist[v][i];
                Ans += Dist[u][i];
                u = P[u][i];
                v = P[v][i];
            }
        }
    }

    Ans += Dist[u][0];
    Ans += Dist[v][0];
    return Ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
	while (cin >> N, N)
	{
		AdjList.assign(N, vii());
		for (int i = 1; i < N; i++)
		{
			int w, v; cin >> v >> w;
			AdjList[i].push_back({v, w});
			AdjList[v].push_back({i, w});
		}
        computeParent(0);
        cin >> Q;
        while(Q--){
            int u, v; cin >> u >> v;
            cout << LCA(u, v) << (!Q ? '\n' : ' ');
        }
	}
}
