#include<bits/stdc++.h>

using namespace std;

typedef vector< int > vi;

bool Visit[110];
vi AdjList[110];
int Count;

void dfs(int at)
{
	Count++;
	Visit[at] = true;
	for (int to : AdjList[at])
	{
		for (int i = 0; i < Count; i++)
			printf("  ");
		if (!Visit[to])
		{
			printf("%d-", at);
			printf("%d pathR(G,%d)\n", to, to);
			dfs(to);
		}
		else
			printf("%d-%d\n", at, to);
	}
	Count--;
}

int main()
{
	int E, T, V; scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		for (int j = 0; j < 110; j++) AdjList[j].clear();
		for (int j = 0; j < 110; j++) Visit[j] = 0;
		int N, M;
		scanf("%d %d", &N, &M);
		for (int j = 0; j < M; j++)
		{
			scanf("%d %d", &V, &E);
			AdjList[V].push_back(E);
		}
		for (int j = 0; j < M; j++) sort(AdjList[j].begin(), AdjList[j].end());
		int Count = 0;
		printf("Caso %d:\n", i + 1);
		for (int j = 0; j < N; j++)
		{
			if (!Visit[j] && AdjList[j].size())
			{
				Count = 0;
				dfs(j);
				printf("\n");
			}
		}
	}
}