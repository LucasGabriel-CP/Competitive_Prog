#include <bits/stdc++.h>

using namespace std;

typedef vector< int > vi;

bool Visit[110];
vi AdjList[110];

void dfs(int at)
{
    Visit[at] = true;
    for	(int to : AdjList[at])
    {
        if	(!Visit[to])
            dfs(to);
    }
}

int main()
{
    int E, T, V; scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {

        for	(int j = 0; j < 110; j++) AdjList[j].clear();
        for	(int j = 0; j < 110; j++) Visit[j] = 0;
        int N, M;
        scanf("%d %d", &N, &M);
        for (int j = 0; j < M; j++)
        {
            scanf("%d %d", &V, &E);
            V--;
            E--;
            AdjList[V].push_back(E);
            AdjList[E].push_back(V);
        }
        int Count = 0;
        printf("Caso #%d: ", i + 1);
        for (int j = 0; j < N; j++)
        {
            if	(!Visit[j])
            {
                Count++;
                dfs(j);
            }
        }
        if	(Count > 1)
            printf("ainda falta(m) %d estrada(s)\n", Count - 1);
        else
            printf("a promessa foi cumprida\n");
    }
}