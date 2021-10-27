#include <bits/stdc++.h>

using namespace std;

#define sz 550
#define inf ~(1<<31)

typedef vector< int > vi;

int Ans, id[550];
bool Visit[sz];
vi AdjList[sz];

int Bes(int Cur, int Ori)
{
    Visit[Cur] = true;

    for (int to : AdjList[Cur])
    {
        if (!Visit[to])
            Ans = min(Ans, id[to]), Bes(to, Ori);
    }

    return Ans;
}

int main()
{
    int N, M, C;
    while (scanf("%d %d %d", &N, &M, &C) != EOF)
    {
        for (int i = 0; i < sz; i++) AdjList[i].clear();
        vi Index(N + 1);
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &id[i]);
            Index[i] = i;
        }
        for (int i = 0; i < M; i++)
        {
            int a, b; scanf("%d %d", &a, &b);
            a--;
            b--;
            AdjList[b].push_back(a);
        }
        for (int j = 0; j < C; j++)
        {
            Ans = inf;
            char Op; scanf(" %c", &Op);
            if (Op == 'P')
            {
                for (int i = 0; i < N; i++) Visit[i] = 0;
                int D; scanf("%d", &D);
                D--;
                Ans = Bes(Index[D], Index[D]);
                if (Ans != inf)
                    printf("%d\n", Ans);
                else
                    printf("*\n");
            }
            else
            {
                int F, S;   scanf("%d %d", &F, &S);
                F--; S--;
                swap(id[Index[F]], id[Index[S]]);
                swap(Index[F], Index[S]);
            }
        }
        for (int i = 0; i < sz; i++) Visit[i] = 0;
    }

    return 0;
}