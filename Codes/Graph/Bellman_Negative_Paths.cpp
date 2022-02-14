//Sort vertices on a DAG
#include <bits/stdc++.h>

using namespace std;

#define MAXN (int)10e5
#define inf (int)1e9

typedef vector<int> vi;
typedef vector<pair<int, int>> vii;

int N, V;
vii AdjList[MAXN];

void BellMan(int S, int D){
    vi Dist(N, inf); Dist[S] = 0;

    for(int i = 0; i < V - 1; ++i){
        bool modified = false;
        for (int u = 0; u < V; ++u){
            if (Dist[u] != inf){
                for (auto to: AdjList[u]){
                    int v = to.first, w = to.second;
                    if (Dist[u] + w >= Dist[v]) continue;
                    Dist[v] = Dist[u] + w;
                    modified = true;
                }
            }
        }
        if (!modified) break;
    }

    bool NegativeCycle = false;
    for (int u = 0; u < V; ++u)
        if (Dist[u] != inf)
            for (auto to: AdjList[u]){
                int v = to.first, w = to.second;
                if (Dist[v] > Dist[u] + w)
                    NegativeCycle = true;
            }
    if (NegativeCycle) printf("Tem ciclo negativo.\n");
    else{
    for (int u = 0; u < V; ++u)
        printf("SSSP(%d, %d) = %d\n", S, u, Dist[u]);
    }
}

int main(){
    BellMan(0, 3);
    return 0;
}
