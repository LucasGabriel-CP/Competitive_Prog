#include <bits/stdc++.h>

using namespace std;

int N;
int Points[110], Tempo[110];
int pd[110][650];

int Brinks(int Ct, int W)
{
	if  (Ct == N)
		return 0;
	if  (pd[Ct][W] != -1)
		return pd[Ct][W];
	if  (Tempo[Ct] > W)
		return Brinks(Ct + 1, W);

	int Op1 = Brinks(Ct + 1, W);
	int Op2 = Points[Ct] + Brinks(Ct + 1, W - Tempo[Ct]);
	int Op3 = Points[Ct] + Brinks(Ct, W - Tempo[Ct]);

	int Ans = max({Op1, Op2, Op3});
 
	pd[Ct][W] = Ans;

	return Ans;
}

int main()
{	
	int Case = 1;
	while(scanf("%d", &N) && N)
	{
		int P;	scanf("%d", &P);

		for (int i = 0; i < N; i++)
			scanf("%d%d", &Tempo[i], &Points[i]);

		memset(pd, -1, sizeof(pd));

		printf("Instancia %d\n", Case);
		Case++;
		printf("%d\n\n", Brinks(0, P));
	}

	return 0;
}