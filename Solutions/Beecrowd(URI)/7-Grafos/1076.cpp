#include<bits/stdc++.h>

using namespace std;

#define sz 50

typedef vector< int > vi;

bool Visit[sz];
vi AdjList[sz];

int x[] = { 0,-1,0,1 }, y[] = { -1,0,1,0 };

int dfs(int at)
{
    int Ans = 1;
    Visit[at] = 1;

    for (int to : AdjList[at])
    {
        if (!Visit[to])
            Ans += dfs(to);
    }

    return Ans;
}

int main()
{
    int Ar, N, Ver, T, V1, V2;

    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &N);

        for (int i = 0; i < sz; i++) Visit[i] = 0;
        for (int i = 0; i < sz; i++) AdjList[i].clear();

        scanf("%d%d", &Ver, &Ar);
        for (int i = 0; i < Ar; i++)
        {
            scanf("%d%d", &V1, &V2);
            AdjList[V1].push_back(V2);
            AdjList[V2].push_back(V1);
        }

        printf("%d\n", (dfs(N) - 1) * 2);
    }
}