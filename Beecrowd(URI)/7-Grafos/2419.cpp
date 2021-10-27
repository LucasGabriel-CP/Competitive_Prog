#include <bits/stdc++.h>

using namespace std;

char Matriz[1050][1050];
int x[] = { 1, -1, 0, 0 };
int y[] = { 0, 0, 1, -1 };
int N, M;

bool valid(int i, int j)
{
	if (i < 0 || i >= N || j < 0 || j >= M) {
		return true;
	}
	return Matriz[i][j] == '.';
}

bool fun(int i, int j)
{
	for (int k = 0; k < 4; k++) {
		if (valid(i + x[k], j + y[k]))
			return true;
	}
	return false;
}

int main()
{
	scanf("%d %d", &N, &M);
	int Ans = 0;
	for (int i = 0; i < N; i++)
		scanf("%s", Matriz[i]);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (Matriz[i][j] == '#' && fun(i, j))
				Ans++;
		}
	}

	printf("%d\n", Ans);

	return 0;
}