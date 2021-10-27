#include <bits/stdc++.h>

using namespace std;

int N;
int Price[100], Peso[1050];
int pd[100][1050];

int Market(int Ct, int W)
{
	if  (Ct == N)
		return 0;
	if  (pd[Ct][W] != -1)
		return pd[Ct][W];
	if  (Peso[Ct] > W)
		return pd[Ct][W] = Market(Ct + 1, W);

	int Op1 = Market(Ct + 1, W);
	int Op2 = Price[Ct] + Market(Ct + 1, W - Peso[Ct]);

	int Ans = max(Op1, Op2);
 
	pd[Ct][W] = Ans;

	return Ans;
}

int main()
{	
	int P;
	int Case = 1;
	while(scanf("%d%d", &P, &N) && N && P)
	{

		for (int i = 0; i < N; i++)
			scanf("%d%d", &Peso[i], &Price[i]);


		memset(pd, -1, sizeof(pd));

		printf("Teste %d\n%d\n\n", Case, Market(0, P));
		Case++;
	}

	return 0;
}