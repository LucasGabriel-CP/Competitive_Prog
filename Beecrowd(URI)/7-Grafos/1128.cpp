#include <bits/stdc++.h>

using namespace std;

typedef vector< int > vi;
typedef vector<vector<int>> vvi;

vvi AdjList;
int Count;

void dfs(int v, vector<bool>& Visit)
{
    Visit[v] = true;
    Count++;
    for (auto u : AdjList[v])
    {
        if (!Visit[u])
            dfs(u, Visit);
    }
}

int main()
{
    int N, M;
    while (scanf("%d %d", &N, &M), N && M)
    {
        AdjList.assign(N, vi());
        for (int i = 0; i < M; i++)
        {
            int A, B, P; scanf("%d %d %d", &A, &B, &P);
            A--;
            B--;
            AdjList[A].push_back(B);
            if (P == 2)
                AdjList[B].push_back(A);
        }

        bool Valid = true;
        for (int i = 0; i < N && Valid; i++)
        {
            Count = 0;
            vector<bool> Visit(N);
            dfs(i, Visit);
            if (Count != N)
                Valid = false;
        }

        printf("%d\n", Valid ? 1 : 0);
    }

    return 0;
}