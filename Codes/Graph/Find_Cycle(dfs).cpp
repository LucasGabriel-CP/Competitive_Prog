/*
	(ˆ ڡ ˆ)yum!
*/

vvi AdjList;
vc Cor;
vi Parent;
bool Cycle;

bool dfs(int v)
{
	Cor[v] = 1;
	for (auto u : AdjList[v])
	{
		if (Cor[u] == 0)
		{
			Parent[u] = v;
			if (dfs(u))
				return true;
		}
		else if (Cor[u] == 1)
		{
			Cycle = true;
			return true;
		}
	}
	Cor[v] = 2;
	return false;
}

bool FindCycle(int N)
{
	Cor.assign(N, 0);
	Parent.assign(N, -1);
	Cycle = false;
	
	for (int i = 0; i < N && !(Cor[i] == 0 && dfs(i)); i++);

	return Cycle;
}