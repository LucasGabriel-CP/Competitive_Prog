#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define inf64 1000000000000000000

typedef pair<int, int> ii;
typedef vector<pair<int, int>> vii;
typedef long long ll;

int N, E;
int AdjList[550][550];

ll Dijkstra(int O, int D)
{
	int W;
	ll Dist[550];
	for (int i = 0; i < 550; i++) Dist[i] = inf64;
	priority_queue<ii, vii, greater<ii>> myPQ;
	Dist[O] = 0;
	myPQ.push(ii(0, O));
	while (!myPQ.empty())
	{
		ii At = myPQ.top();
		myPQ.pop();
		for (int it = 0; it < N; it++)
		{
			if (AdjList[At.s][it] != -1)
			{
				if (AdjList[it][At.s] != -1)
				{
					W = 0;
					if (Dist[it] > Dist[At.s] + W)
					{
						Dist[it] = Dist[At.s] + W;
						myPQ.push(ii(W, it));
					}
				}
				else
				{
					W = AdjList[At.s][it];
					if (Dist[it] > Dist[At.s] + W)
					{
						Dist[it] = Dist[At.s] + W;
						myPQ.push(ii(W, it));
					}
				}
			}
		}
	}
	return Dist[D];
}

int main()
{
	int O, K, D;
	while (scanf("%d %d", &N, &E) != EOF && (N || E))
	{
		for (int i = 0; i < 550; i++)
			for (int j = 0; j < 550; j++)
				AdjList[i][j] = -1;
		for (int i = 0; i < E; i++)
		{
			int U, V, P;
			scanf("%d %d %d", &U, &V, &P);
			U--;
			V--;
			AdjList[U][V] = P;
		}
		scanf("%d", &K);
		while (K--)
		{
			scanf("%d %d", &O, &D);
			O--;
			D--;
			ll Ans = Dijkstra(O, D);
			if (Ans != inf64)
				printf("%lld\n", Ans);
			else
				printf("Nao e possivel entregar a carta\n");
		}
		printf("\n");
	}
}