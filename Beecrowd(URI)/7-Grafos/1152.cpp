#include <bits/stdc++.h>

using namespace std;

#define sz 200050
#define f first
#define s second

struct aresta
{
    long a, b, p;
};
bool Comp(aresta a, aresta b) { return a.p < b.p; }
bool CompMax(aresta a, aresta b) { return a.p > b.p; }

long pai[sz];
long long Rank[sz];
vector< aresta > Lis;

long acha_pai(long X)
{
    if (pai[X] == X)
        return X;
    return pai[X] = acha_pai(pai[X]);
}

void unir(long X, long Y)
{
    X = acha_pai(X);
    Y = acha_pai(Y);
    if (Rank[X] > Rank[Y])
    {
        pai[Y] = X;
        Rank[X]++;
    }
    else
    {
        pai[X] = Y;
        Rank[Y]++;
    }
}

int main()
{
    long M, N;
    scanf("%d %d", &M, &N);

    while (M != 0 && N != 0)
    {
        long MaxW = 0;
        for (long i = 0; i < M; i++) pai[i] = i;
        for (long i = 0; i < M; i++) Rank[i] = 1;

        aresta Cabo;
        long U, V, W;
        for (long i = 0; i < N; i++)
        {
            scanf("%d %d %d", &U, &V, &W);
            Cabo.a = U;
            Cabo.b = V;
            Cabo.p = W;
            Lis.push_back(Cabo);
            MaxW += W;
        }
        long S = 0;

        sort(Lis.begin(), Lis.end(), Comp);
        for (long i = 0; i < Lis.size(); i++)
        {
            long X = Lis[i].a;
            long Y = Lis[i].b;
            long Z = Lis[i].p;
            if (acha_pai(X) != acha_pai(Y))
            {
                S += Z;
                unir(X, Y);
            }
        }
        printf("%ld\n", MaxW - S);

        Lis.clear();
        scanf("%ld %ld", &M, &N);
    }
}