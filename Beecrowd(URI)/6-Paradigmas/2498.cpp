#include <bits/stdc++.h>

using namespace std;

#define sz 10050

int N;
int Peso[sz], Pt[sz], pd[sz][sz];

int Knap(int at, int w)
{
	if (at >= N)
		return 0;
	if (pd[at][w] != -1)
		return pd[at][w];
	if (Peso[at] > w)
		return pd[at][w] = Knap(at + 1, w);
	int op1 = Pt[at] + Knap(at + 1, w - Peso[at]);
	int op2 = Knap(at + 1, w);

	return pd[at][w] = max(op1, op2);
}

int main()
{
	int C, Count = 1;
	while (scanf("%d %d", &N, &C), N && C)
	{
		for (int i = 0; i < N; i++)
			scanf("%d %d", &Peso[i], &Pt[i]);
		for (int i = 0; i <= N; i++)
			for (int j = 0; j <= C; j++)
				pd[i][j] = -1;
		printf("Caso %d: %d\n", Count++, Knap(0, C));
	}

	return 0;
}