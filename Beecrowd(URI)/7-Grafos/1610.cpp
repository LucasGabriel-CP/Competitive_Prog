#include <bits/stdc++.h>

using namespace std;

typedef vector< int > vi;
typedef vector< char > vc;
typedef vector<vector<int>> vvi;

vvi AdjList;
vc Cor;
bool Cycle;

bool dfs(int v)
{
    Cor[v] = 1;
    for (auto u : AdjList[v])
    {
        if (Cor[u] == 0)
        {
            if (dfs(u))
                return true;
        }
        else if (Cor[u] == 1)
        {
            Cycle = true;
            return true;
        }
    }
    Cor[v] = 2;
    return false;
}

bool FindCycle(int N)
{
    Cor.assign(N, 0);
    Cycle = false;

    for (int i = 0; i < N && !(Cor[i] == 0 && dfs(i)); i++);

    return Cycle;
}

int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        int N, M; scanf("%d %d", &N, &M);
        AdjList.assign(N, vi());
        for (int i = 0; i < M; i++)
        {
            int A, B; scanf("%d %d", &A, &B);
            A--;
            B--;
            AdjList[A].push_back(B);
        }
        printf("%s\n", FindCycle(N) ? "SIM" : "NAO");
    }
}