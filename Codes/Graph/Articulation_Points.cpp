int N, M, Timer;
vector<bool> Visit;
vi AdjList[10050], tin, low;
set<int> Cut;

void DFS(int u, int p = -1){
	Visit[u] = true;
	tin[u] = low[u] = Timer++;
	int children = 0;
	for (int v : AdjList[u]){
		if (to == p)
            continue;
		if (Visit[v])
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
	Timer = 0;
	Visit.assign(N, false);
	tin.assign(N, -1);
	low.assign(N, -1);

	for (int i = 0; i < N; i++){
		if (!Visit[i])
			DFS(i);
	}
}
