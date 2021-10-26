#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int Vet[100050];

int main()
{
    int N;
    while (scanf("%d", &N), N)
    {
        for (int i = 0; i < N; i++)
            scanf("%d", &Vet[i]);
        ll Ans;
        Ans = 0;
        for (int i = 1; i < N; i++)
        {
            if (Vet[i] < 0)
            {
                Ans += abs(Vet[i - 1]);
                Vet[i] += Vet[i - 1];
            }
            else
            {
                Ans += abs(Vet[i - 1]);
                Vet[i] += Vet[i - 1];
            }
        }
        printf("%lld\n", Ans);
    }

    return 0;
}