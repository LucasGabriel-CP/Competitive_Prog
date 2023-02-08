#include<bits/stdc++.h>

int n, m, timer;

std::vector<bool> vis;
std::vector<bool> AdjList[10050], tin, low;
std::set<int> Cut;

void DFS(int u, int p = -1){
	vis[u] = true;
	tin[u] = low[u] = timer++;
	int children = 0;
	for (int v : AdjList[u]){
		if (v == p)
            continue;
		if (vis[v])
			low[u] = min(low[u], tin[v]);
		else{
			DFS(v, u);
			low[u] = min(low[u], low[v]);
			if (low[v] >= tin[u] && p != -1)
				Cut.insert(u);
			++children;
		}
	}
	if (p == -1 && children > 1) Cut.insert(u);
}

void FindAtCut(){
	timer = 0;
	vis.assign(n, false);
	tin.assign(n, -1);
	low.assign(n, -1);

	for (int i = 0; i < n; i++){
		if (!vis[i])
			DFS(i);
	}
}
