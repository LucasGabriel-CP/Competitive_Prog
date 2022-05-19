#include <bits/stdc++.h>
#define f first
#define s second
#define inf (int)1e9
#define MAXN 105

using namespace std;

vector<int> AdjList[MAXN];
vector<int> Dist;
vector<int> Custo;
set<int> mySet;
vector<bool> vis;
int n, m;

void dfs(int u){
	vis[u] = true;
	for (int v : AdjList[u])
		if (!vis[v])
			dfs(v);
}

void Bellman(){
	Dist.assign(n, inf);
	Dist[0] = 0;
	for (int i = 0; i < n - 1; ++i){
        bool modified = false;
        for (int j = 0; j < n; ++j){
            if (Dist[j] != inf){
                for (auto to : AdjList[j]){
                    if (Dist[to] > Dist[j] + Custo[to] && Dist[j] + Custo[to] < 100){
                        modified = true;
                        Dist[to] = Dist[j] + Custo[to];
                    }
                }
            }
        }
        if (!modified) break;
	}
	for (int i = 0; i < n - 1; ++i){
        if (Dist[i] != inf){
            for (auto to : AdjList[i]){
                if (Dist[to] > Dist[i] + Custo[to] && Dist[i] + Custo[to] < 100){
                    Dist[to] = -inf;
                    mySet.insert(to);
                }
            }
        }
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> n, n != -1){
        for(int i = 0; i < n; ++i) AdjList[i].clear();
        Custo.resize(n);
        vis.assign(n, false);
        mySet.clear();
        for (int i = 0; i < n; ++i){
            int a, m; cin >> Custo[i] >> m;
            Custo[i] *= -1;
            for (int j = 0; j < m; ++j){
                cin >> a; --a;
                AdjList[i].push_back(a);
            }
        }
        Bellman();
		dfs(0);
		bool ok = false;
		for(int i : mySet){
			if (vis[i]){
				vis.assign(n, false);
				dfs(i);
				if (vis[n - 1]){ ok = true; break; }
			}
		}
		if (ok){
			cout << "winnable\n";
		}
		else
			cout << (Dist[n - 1] < 100 ? "winnable\n" : "hopeless\n");
    }

	return 0;
}
