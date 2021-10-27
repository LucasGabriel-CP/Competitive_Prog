#include <bits/stdc++.h>

using namespace std;

int N;
int Dano[110], Carga[110];
int pd[110][110];

int Galho(int Ct, int W)
{
    if  (Ct == N)
        return 0;
    if  (pd[Ct][W] != -1)
        return pd[Ct][W];
    if  (Carga[Ct] > W)
        return Galho(Ct + 1, W);
    int Op1 = Galho(Ct + 1, W);
    int Op2 = Dano[Ct] + Galho(Ct + 1, W - Carga[Ct]);
    int Ans = max(Op1, Op2);

    pd[Ct][W] = Ans;

    return Ans;
}

int main()
{
    int Case;	scanf("%d", &Case);
    for (int i = 0; i < Case; i++)
    {
        scanf("%d", &N);
        int P;	scanf("%d", &P);

        for (int i = 0; i < N; i++)
            scanf("%d%d", &Dano[i], &Carga[i]);

        memset(pd, -1, sizeof(pd));

        printf("Galho %d:\n", i + 1);
        printf("Numero total de enfeites: %d\n\n", Galho(0, P));
    }

    return 0;
}