
viii Edge;	//a -> b, custo

void printPath(int D, vi Pre)
{
	vi path;
	for (int i = D; i != -1; i = Pre[i])
		path.push_back(i);

	for (int i = path.size() - 1; i > 0; i--)
		printf("%d ", path[i]);
	printf("%d", path.back());
}

int Ford(int O, int D, int N, int M)
{
	vi Dist(N, inf);
	vi Pre(N, -1);
	Dist[O] = 0;
	bool change = true;
	while (change)
	{
		change = false;
		for (int i = 0; i < M; i++)
		{
			if (Dist[Edge[i].f] < inf)
			{
				if (Dist[Edge[i].s.f] > Dist[Edge[i].f] + Edge[i].s.s)
				{
					Dist[Edge[i].s.f] = Dist[Edge[i].f] + Edge[i].s.s;
					Pre[Edge[i].s.f] = Edge[i].f;
					change = true;
				}
			}
		}
	}

	return Dist[D];
}