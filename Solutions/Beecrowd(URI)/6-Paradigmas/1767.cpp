#include <bits/stdc++.h>

using namespace std;

typedef vector< int > vi;

int Ans, N;
int Price[350], Peso[100];
int pd[150][100];
vi VetRec;

int Noel(int Ct, int W)
{
    if (Ct >= N)
        return 0;
    if (pd[Ct][W] != -1)
        return pd[Ct][W];
    if (Peso[Ct] > W)
        return pd[Ct][W] = Noel(Ct + 1, W);

    int Op1 = Noel(Ct + 1, W);
    int Op2 = Price[Ct] + Noel(Ct + 1, W - Peso[Ct]);

    return pd[Ct][W] = max(Op1, Op2);
}

void Rec(int Ct, int W)
{
    if (Ct >= N)
        return;
    if (Peso[Ct] > W)
        return Rec(Ct + 1, W);
    int Choice = Noel(Ct, W);
    int Op1 = Price[Ct] + Noel(Ct + 1, W - Peso[Ct]);
    int Op2 = Noel(Ct + 1, W);

    if (Choice == Op1)
    {
        VetRec.push_back(Ct);
        return Rec(Ct + 1, W - Peso[Ct]);
    }
    else
        return Rec(Ct + 1, W);
}

int main()
{
    int Case;
    scanf("%d", &Case);
    while (Case--)
    {
        int PesoTot = 0, Brinks, Total = 0;
        Ans = 0;
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
        {
            scanf("%d %d", &Price[i], &Peso[i]);
            Total += Price[i];
        }

        memset(pd, -1, sizeof(pd));
        Brinks = Noel(0, 50);
        Rec(0, 50);

        printf("%d brinquedos\n", Brinks);
        for (int i = 0; i < VetRec.size(); i++)
            PesoTot += Peso[VetRec[i]];
        printf("Peso: %d kg\n", PesoTot);
        printf("sobra(m) %d pacote(s)\n\n", N - VetRec.size());

        VetRec.clear();
    }

    return 0;
}