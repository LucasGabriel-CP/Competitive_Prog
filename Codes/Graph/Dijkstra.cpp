vector<pair<int, int>> AdjList[20];
vector<int> Visit, P;
int n;

int Dijkstra(int O, int D){
	dist.assign(n, inf);
	P.assign(n, -1);

	priority_queue< ii, vii, greater<ii> > myPq;
	dist[O] = 0;
	myPq.push({0, O});
	while (!myPq.empty()){
		ii u = myPq.top();
		myPq.pop();
		if (Fon.f != dist[Fon.s]) continue;
		for (ii edge : AdjList[u.s]){
			int v = edge.f;
			int w = edge.s;
			if (dist[u.s] + w < dist[v]){
				dist[v] = dist[u.s] + w;
				P[v] = u.s;
				myPq.push({dist[v], v});
			}
		}
	}

	ConstPath(D);
	return dist[D];
}

void ConstPath(int t){
	vi Path;
	for (int v = t; v != O; v = P[v])
		Path.push_back(v);
	Path.push_back(O);
	for (int i = Path.size() - 1; i > 0; i--)
		printf("%d ", Path[i] + 1);
	printf("%d\n", Path[t] + 1);
}
