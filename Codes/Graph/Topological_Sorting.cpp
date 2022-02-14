//Sort vertices on a DAG
#include <bits/stdc++.h>

using namespace std;

#define MAXN (int)10e5
typedef vector<int> vi;

int N;
bool visit[MAXN];
vi AdjList[MAXN], ts;

void dfs(int u){
    visit[u] = true;
    for (auto v : AdjList[u])
        if (!visit[v])
            dfs(v);
    ts.push_back(u);
}

void TopoSort(){
    memset(visit, false, N);
    for (int i = 0; i < N; ++i)
        if (!visit[i]) dfs(i);
    reverse(ts.begin(), ts.end());
}
