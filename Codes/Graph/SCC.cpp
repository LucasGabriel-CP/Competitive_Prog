vector<bool> Visit;
vvi AdjList, AdjRe;
vi Order, Component;		//Da o resultado ao contrário

void dfs1(int v)
{
	Visit[v] = true;
	for (int u : AdjList[v])
		if (!Visit[u])
			dfs1(u);
	Order.push_back(v);
}

void dfs2(int v)
{
	Visit[v] = true;
	Component.push_back(v);
	for (int u : AdjRe[v])
		if (!Visit[u])
			dfs2(u);
}

int main()
{
	//freopen("input.txt", "r", stdin);
	int N;	scanf("%d", N);
	AdjList.assign(N, vi());
	AdjRe.assign(N, vi());
	while (true)
	{
		int a, b;	scanf("%d %d", &a, &b);
		AdjList[a].push_back(b);
		AdjList[b].push_back(a);
	}
	
	Visit.assign(N, false);
	for (int i = 0; i < N; i++)
		if (!Visit[i])
			dfs1(i);

	//Pegar o grafo transposto
	Visit.assign(N, false);
	reverse(Order.begin(), Order.end());

	for (int i : Order)
	{
		if (!Visit[i])
		{
			dfs2(i);
			//Process data
			Component.clear();
		}
	}

	return 0;
}