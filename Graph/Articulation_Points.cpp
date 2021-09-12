
int N, M, Timer;
vector<bool> Visit;
vi AdjList[10050], tin, low;
map<int, int> Cut;

void DFS(int v, int p = -1)
{
	Visit[v] = true;
	tin[v] = low[v] = Timer++;
	int children = 0;
	for (int to : AdjList[v])
	{
		if (to == p)	continue;
		if (Visit[to])
			low[v] = min(low[v], tin[to]);
		else
		{
			DFS(to, v);
			low[v] = min(low[v], low[to]);
			if (low[to] >= tin[v] && p != -1)
				Cut[v]++;
			++children;
		}
	}
	if (p == -1 && children > 1)	Cut[v]++;
}

void FindAtCut()
{
	Timer = 0;
	Visit.assign(N, false);
	tin.assign(N, -1);
	low.assign(N, -1);

	for (int i = 0; i < N; i++)	
	{
		if (!Visit[i])
			DFS(i);
	}
}