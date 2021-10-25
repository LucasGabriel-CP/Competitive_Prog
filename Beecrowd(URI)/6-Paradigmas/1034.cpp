#include<bits/stdc++.h>

using namespace std;

#define inf ~(1<<31) - 1

int N, M;
int pd[1000002], Moedas[30];

void CC()
{
    pd[0] = 0;
    for (int c = 1; c <= M; ++c)
    {
        auto& dp = pd[c] = inf;
        for (int i = 0; i < N; ++i)
            if (c >= Moedas[i])
                dp = min(dp, pd[c - Moedas[i]] + 1);
    }
}

int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d", &N, &M);

        for (int i = 0; i < N; i++)
        {
            scanf("%d", &Moedas[i]);
        }
        CC();
        printf("%d\n", pd[M]);
    }

    return 0;
}