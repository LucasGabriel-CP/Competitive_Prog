#include<bits/stdc++.h>

using namespace std;

int Vet[10010];

int main()
{
    int N, K, Result;
    while (scanf("%d", &N) && N != 0)
    {
        K = 0;
        int At = 0, Aux = N;
        if (N == 13)
            printf("1\n");
        else
        {
            do
            {
                K++;
                for (int j = 0; j < 150; j++)
                    Vet[j] = j + 1;
                while (N != 1)
                {
                    for (int i = At; i < N - 1; i++)
                        Vet[i] = Vet[i + 1];
                    At = (At + K) % (N - 1);
                    N--;
                }
                Result = Vet[At];
                N = Aux;
            } while (Result != 13);
            printf("%d\n", K + 1);
        }
    }

    return 0;
}