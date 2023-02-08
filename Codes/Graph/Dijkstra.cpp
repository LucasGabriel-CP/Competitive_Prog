#include<bits/stdc++.h>

const int inf = (int)1e8;
std::vector<std::pair<int, int>> AdjList[20];
std::vector<int> dist, parent;
int n;

int Dijkstra(int O, int D){
	dist.assign(n, inf);
	parent.assign(n, -1);

	std::priority_queue< std::pair<int, int>, std::vector<std::pair<int, int>>,
						std::greater<std::pair<int, int>> > myPq;
	dist[O] = 0;
	myPq.push({0, O});
	while (!myPq.empty()){
		auto [d, u] = myPq.top();
		myPq.pop();
		if (d > dist[u]) continue;
		for (auto[v, w]: AdjList[u]){
			if (d + w < dist[v]){
				dist[v] = d + w;
				parent[v] = u;
				myPq.push({dist[v], v});
			}
		}
	}

	ConstPath(O, D);
	return dist[D];
}

void ConstPath(int o, int t){
	std::vector<int> Path;
	for (int v = t; v != o; v = parent[v])
		Path.push_back(v);
	Path.push_back(o);
	for (int i = Path.size() - 1; i > 0; i--)
		printf("%d ", Path[i] + 1);
	printf("%d\n", Path[t] + 1);
}
