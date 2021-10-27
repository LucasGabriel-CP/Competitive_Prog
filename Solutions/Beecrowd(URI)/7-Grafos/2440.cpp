#include <bits/stdc++.h>

using namespace std;


#define sz 50050

typedef vector< int > vi;

bool Visit[sz];
vi AdjList[sz];

int x[] = { 0,-1,0,1 }, y[] = { -1,0,1,0 };

void dfs(int at)
{

	Visit[at] = 1;
	for (int to : AdjList[at])
	{
		if (!Visit[to])
			dfs(to);
	}

}

int main()
{
	int M, N, V1, V2;
	for (int i = 0; i < sz; i++) Visit[i] = 0;
	scanf("%d %d", &M, &N);

	while (N--)
	{
		scanf("%d %d", &V1, &V2);
		AdjList[V1].push_back(V2);
		AdjList[V2].push_back(V1);
	}

	int Count = 0;
	for (int i = 1; i <= M; i++)
	{
		if (!Visit[i])
		{
			Count++;
			dfs(i);
		}
	}
	printf("%d\n", Count);
}