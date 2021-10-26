#include <bits/stdc++.h>

using namespace std;

int N;
int Dano[110], Carga[110];
int pd[110][110];

int Canhao(int Ct, int W)
{
    if (Ct == N)
        return 0;
    if (pd[Ct][W] != -1)
        return pd[Ct][W];
    if (Carga[Ct] > W)
        return Canhao(Ct + 1, W);
    int Op1 = Canhao(Ct + 1, W);
    int Op2 = Dano[Ct] + Canhao(Ct + 1, W - Carga[Ct]);
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
        for (int i = 0; i < N; i++)
            scanf("%d%d", &Dano[i], &Carga[i]);

        int P;	scanf("%d", &P);
        memset(pd, -1, sizeof(pd));

        int Barreira;	scanf("%d", &Barreira);
        if (Canhao(0, P) >= Barreira)
            printf("Missao completada com sucesso\n");
        else
            printf("Falha na missao\n");
    }

    return 0;
}