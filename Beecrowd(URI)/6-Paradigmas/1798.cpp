#include <bits/stdc++.h>

using namespace std;

int N, Tam;
int Cano[5050];
int Value[5050];
int DP[5050][5050];

int x[] = {0,-1,0,1}, y[] = {-1,0,1,0};

int knapsack(int Ct, int W)
{
    if (Ct >= N)
        return 0;
    if (DP[Ct][W] != -1)
        return DP[Ct][W];
    if (Cano[Ct] > W)
        return DP[Ct][W] = knapsack(Ct+1, W);
    int Op1 = knapsack(Ct + 1, W);
    int Op2 = Value[Ct] + knapsack(Ct, W - Cano[Ct]);

    return DP[Ct][W] = max(Op1, Op2);
}

int main()
{
    while(scanf("%d", &N) != EOF)
    {
        scanf("%d", &Tam);

        for (int i = 0; i < N; i++)
            scanf("%d %d", &Cano[i], &Value[i]);
        for (int i = 0; i < N; i++)
            for (int j = 0; j <= Tam; j++)
                DP[i][j] = -1.0;
        int Ans = knapsack(0, Tam);
        printf("%d\n", Ans);
    }
}