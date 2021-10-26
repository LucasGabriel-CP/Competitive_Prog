#include <bits/stdc++.h>

using namespace std;

typedef vector< int > vi;

vi AdjList[1050];
char Matriz[1050][1050];
bool Visit[1050];

bool comp(int a, int b) { return a > b; }

int DFS(int Cur, int C, vi& QntC)
{
	int Ans = 1;
	QntC[Cur] = C;

	for (int to : AdjList[Cur])
	{
		if (!QntC[to])
			Ans += DFS(to, C, QntC);
	}

	return Ans;
}

int main()
{
	int N; scanf("%d", &N);
	char Aux;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			scanf(" %c", &Aux);
			Matriz[i][j] = Aux;
			if (Aux == 'S' && i != j)
				AdjList[i].push_back(j);
		}

	vi Ans, QntC(N + 1, 0);
	int Componentes = 0;
	for (int i = 0; i < N; i++)
	{
		if (!QntC[i])
		{
			Componentes++;
			int Count = DFS(i, Componentes, QntC);
			Ans.push_back(Count);
		}
	}
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			if (Matriz[i][j] == 'D' && QntC[i] == QntC[j])
			{
				printf("-1\n");
				return 0;
			}
		}

	sort(Ans.begin(), Ans.end(), comp);
	printf("%d\n%d", Ans.size(), Ans[0]);
	for (int i = 1; i < Ans.size(); i++)
		printf(" %d", Ans[i]);
	printf("\n");

	return 0;
}