#include <bits/stdc++.h>

using namespace std;

int main()
{
    int Vet[240];
    int Qnt, N, Maior;
    int T; scanf("%d", &T);
    while (T--)
    {
        for (int i = 19; i < 231; i++) Vet[i] = 0;
        scanf("%d", &Qnt);
        Maior = 0;
        for (int i = 0; i < Qnt; i++)
        {
            scanf("%d", &N);
            Vet[N]++;
            Maior = Maior < N ? N : Maior;
        }
        for (int i = 19; i < Maior; i++)
        {
            while (Vet[i])
            {
                printf("%d ", i);
                Vet[i]--;
            }
        }
        while (Vet[Maior] > 1)
        {
            printf("%d ", Maior);
            Vet[Maior]--;
        }

        printf("%d\n", Maior);
    }

    return 0;
}