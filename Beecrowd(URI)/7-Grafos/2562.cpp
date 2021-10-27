#include <bits/stdc++.h>

using namespace std;

typedef vector< int > vi;

int N, M, Ans;
bool Visit[1050];
vi AdjList[1050];

void DFS(int u)
{
	Visit[u] = true;
	Ans++;
	for (int i : AdjList[u])
	{
		if (!Visit[i])
			DFS(i);
	}
}

int main()
{
	while (scanf("%d %d", &N, &M) != EOF)
	{
		for (int i = 0; i < 1050; ++i) Visit[i] = false;
		for (int i = 0; i < M; ++i)
		{
			int a, b; scanf("%d %d", &a, &b);
			AdjList[a].push_back(b);
			AdjList[b].push_back(a);
		}
		int E; scanf("%d", &E);
		Ans = 0;
		DFS(E);
		printf("%d\n", Ans);
		for (int i = 0; i < 1050; ++i) AdjList[i].clear();
	}

	return 0;
}