#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

typedef pair<int, int> ii;

int Matriz[1050][1050];
bool Visit[1050][1050];
int x[] = { 1, -1, 0, 0 };
int y[] = { 0, 0, 1, -1 };
int N, M;

bool valid(int i, int j)
{
	if (i < 0 || i >= N || j < 0 || j >= M) {
		return false;
	}
	return Matriz[i][j] == 1;
}

int main()
{
	scanf("%d %d", &N, &M);
	int Ans = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d", &Matriz[i][j]);

	queue<ii> q;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			Visit[i][j] = false;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (Visit[i][j] || !Matriz[i][j]) continue;
			q.push({ i, j });
			Visit[i][j] = true;
			while (!q.empty())
			{
				ii v = q.front();
				q.pop();
				for (int k = 0; k < 4; k++) {
					if (valid(v.f + x[k], v.s + y[k]) && !Visit[v.f + x[k]][v.s + y[k]])
					{
						Visit[v.f + x[k]][v.s + y[k]] = true;
						q.push({ v.f + x[k], v.s + y[k] });
					}
				}
			}
			Ans++;
		}
	}
	printf("%d\n", Ans);

	return 0;
}