#include <bits/stdc++.h>

using namespace std;

int N;
int Price[1050], Peso[250];
int pd[150][250];

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
    while(scanf("%d", &N) && N)
    {
        for (int i = 0; i < N; i++)
            scanf("%d%d", &Price[i], &Peso[i]);

        int P;	scanf("%d", &P);

        memset(pd, -1, sizeof(pd));

        printf("%d\n", Market(0, P));
    }

    return 0;
}