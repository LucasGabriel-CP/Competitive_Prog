#include <bits/stdc++.h>

using namespace std;

#define sz 60

bool Visit[sz][sz];
char Matriz[sz][sz];

int x[] = { 0,-1,0,1 }, y[] = { -1,0,1,0 };
int N, M;

void dfs(int u, int v)
{
	Visit[u][v] = 1;

	for (int i = 0; i < 4; i++)
	{
		int a = u + x[i];
		int b = v + y[i];
		if ((a >= 0 && a < N) && (b >= 0 && b < M) && (!Visit[a][b] && Matriz[a][b] == 'A'))
		{
			Matriz[a][b] = 'T';
			dfs(a, b);
		}
	}

}

int main()
{
	int L, C;

	scanf("%d%d", &N, &M);
	while (N != 0 && M != 0)
	{

		for (int i = 0; i < sz; i++)
			for (int j = 0; j < sz; j++)
				Visit[i][j] = 0;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				scanf(" %c", &Matriz[i][j]);

		for (L = 0; L < N; L++)
			for (C = 0; C < M; C++)
			{
				if (!Visit[L][C] && Matriz[L][C] == 'T')
				{
					dfs(L, C);
				}
			}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
				printf("%c", Matriz[i][j]);
			printf("\n");
		}
		printf("\n");
		scanf("%d%d", &N, &M);
	}
}