#include <bits/stdc++.h>

using namespace std;

bool Visit[50][50];
int G[10][10];

bool dfs(int u, int v)
{
    if	(u < 0 || u >= 5 || v < 0 || v >= 5)
        return false;
    if	(G[u][v] == 1)
        return false;
    if	(Visit[u][v] == 1)
        return false;
    if	(u == 4 && v == 4)
        return true;
        
    Visit[u][v] = 1;

    bool C1 = dfs(u + 1, v);
    bool C2 = dfs(u - 1, v);
    bool C3 = dfs(u, v + 1);
    bool C4 = dfs(u, v - 1);

    if	(C1 || C2 || C3 || C4)
        return true;
    return false;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        for	(int i = 0; i < 5; i++)
            for	(int j = 0; j < 5; j++)
                scanf("%d", &G[i][j]);
        for	(int i = 0; i < 5; i++)
            for	(int j = 0; j < 5; j++)
                Visit[i][j] = 0;
        if	(dfs(0,0))
            printf("COPS\n");
        else
            printf("ROBBERS\n");
    }
}