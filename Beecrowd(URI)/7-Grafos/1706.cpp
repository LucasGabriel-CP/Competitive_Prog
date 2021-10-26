#include <bits/stdc++.h>

using namespace std;

#define sz 1010

typedef vector< int > vi;

char Let[1050];
bool Visit[sz];
vi AdjList[sz];

int Bes(int Cur)
{
    Visit[Cur] = true;
    int Ans = 0;
    if (Let[Cur] == 'B')
        Ans = 1;
    for (int to : AdjList[Cur])
    {
        if (!Visit[to])
            Ans += Bes(to);
    }
    return Ans;
}

int main()
{
    int N, M;
    while (scanf("%d %d", &N, &M) != EOF)
    {
        bool Da = true;
        for (int i = 0; i < N; i++) AdjList[i].clear();
        for (int i = 0; i < N; i++) Visit[i] = 0;
        for (int i = 0; i < N; i++)
        {
            scanf(" %c", &Let[i]);
        }
        for (int i = 0; i < M; i++)
        {
            int a, b; scanf("%d %d", &a, &b);
            a--;
            b--;
            AdjList[a].push_back(b);
            AdjList[b].push_back(a);
        }
        for (int i = 0; i < N; i++)
        {
            if (!Visit[i])
            {
                int Count = Bes(i);
                if (Count % 2)
                    Da = false;
            }
        }
        if (Da)
            printf("Y\n");
        else
            printf("N\n");
    }
}