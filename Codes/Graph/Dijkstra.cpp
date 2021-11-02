//Dijkstra
//Priority queue com pair
//Pair 		-> Peso / Vértice
//Visitados -> Peso inicial como infinito

vii AdjList[20];
vi Visit, P;

void Dijkstra(int O, int D)
{
	int N = AdjList.size();
	Visit.assign(N, inf);
	P.assign(N, -1);

	priority_queue< ii, vii, greater<ii> > myPq;
	Visit[O] = 0;
	myPq.push({ 0, O });
	while (!myPq.empty())
	{
		ii Fon = myPq.top();
		myPq.pop();
		if (Fon.f != Visit[Fon.s]) continue;

		for (ii edge : AdjList[Fon.s])
		{
			int to = edge.f;
			int len = edge.s;
			if (Visit[Fon.s] + len < Visit[to])
			{
				Visit[to] = Visit[Fon.s] + len;
				P[to] = Fon.s;
				myPq.push({ Visit[to], to });
			}
		}
	}
	
	int Ans = Visit[D];
	ConstPath(D);
}

void ConstPath(int t)
{
	vi Path;
	for (int v = t; v != O; v = P[v])
		Path.push_back(v);
	Path.push_back(O);
	for (int i = Path.size() - 1; i > 0; i--)
		printf("%d ", Path[i] + 1);
	printf("%d\n", Path[t] + 1);
}