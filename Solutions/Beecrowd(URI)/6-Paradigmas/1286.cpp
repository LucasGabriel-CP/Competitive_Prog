#include <bits/stdc++.h>

using namespace std;

int N;
int Tempo[40], Peso[40];
int pd[100][100];

int Pizza(int Ct, int W)
{
	if (Ct == N)
		return 0;
	if (pd[Ct][W] != -1)
		return pd[Ct][W];
	if (Peso[Ct] > W)
		return Pizza(Ct + 1, W);
	int Op1 = Pizza(Ct + 1, W);
	int Op2 = Tempo[Ct] + Pizza(Ct + 1, W - Peso[Ct]);
	int Ans = max(Op1, Op2);

	pd[Ct][W] = Ans;

	return Ans;
}

int main()
{
	while (scanf("%d", &N) && N)
	{
		int P;	scanf("%d", &P);
		memset(pd, -1, sizeof(pd));
		for (int i = 0; i < N; i++)
			scanf("%d%d", &Tempo[i], &Peso[i]);
		printf("%d min.\n", Pizza(0, P));
	}

	return 0;
}