#include <bits/stdc++.h>

using namespace std; 

#define sz 70

struct aresta
{
    int a, b, p;
};
bool Comp(aresta a, aresta b) { return a.p < b.p; }

int pai[sz];
int Rank[sz];
vector< aresta > Lis;

int acha_pai(int X)
{
    if (pai[X] == X)
        return X;
    return pai[X] = acha_pai(pai[X]);
}

void unir(int X, int Y)
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
    int R, C; scanf("%d %d", &R, &C);

    for (int i = 0; i < R; i++) pai[i] = i;
    for (int i = 0; i < R; i++) Rank[i] = 1;

    aresta Cabo;
    int V, W, P;
    for (int i = 0; i < C; i++)
    {
        scanf("%d %d %d", &V, &W, &P);
        Cabo.a = V - 1;
        Cabo.b = W - 1;
        Cabo.p = P;
        Lis.push_back(Cabo);
    }
    sort(Lis.begin(), Lis.end(), Comp);

    vector< aresta > Ans;
    int S = 0;
    for (int i = 0; i < Lis.size(); i++)
    {
        int X = Lis[i].a;
        int Y = Lis[i].b;
        int Z = Lis[i].p;
        if (acha_pai(X) != acha_pai(Y))
        {
            Ans.push_back(Lis[i]);
            S += Z;
            unir(X, Y);
        }
    }
    printf("%d\n", S);
}