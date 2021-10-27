#include <bits/stdc++.h>

using namespace std;

#define sz 10050

int N;
int pd[sz][sz], Pt[sz], Peso[sz];

int Knap(int at, int w)
{
	if (at >= N)
		return 0;
	if (pd[at][w] != -1)
		return pd[at][w];
	if (Peso[at] > w)
		return pd[at][w] = Knap(at + 1, w);

	int Op1 = Pt[at] + Knap(at + 1, w - Peso[at]);
	int Op2 = Knap(at + 1, w);

	return pd[at][w] = max(Op1, Op2);
}

int main()
{
	int K;
	while (scanf("%d %d", &N, &K) != EOF)
	{
		for (int i = 0; i < N + 1; ++i)
			for (int j = 0; j < K + 1; ++j)
				pd[i][j] = -1;

		for (int i = 0; i < N; i++)
			scanf("%d", &Pt[i]);
		for (int i = 0; i < N; i++)
			scanf("%d", &Peso[i]);
		printf("%d\n", Knap(0, K));
	}

	return 0;
}