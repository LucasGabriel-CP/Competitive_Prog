#include <bits/stdc++.h>

using namespace std;

#define sz 500
#define f first
#define s second
#define inf 1000000000

typedef pair<int, int> ii;
typedef vector< int > vi;
typedef vector<pair<int, int>> vii;

int main()
{
    int N, M, C, K;
    int Dist[300];
    vii AdjList[300];
    int Peso[300][300];
    while (scanf("%d %d %d %d", &N, &M, &C, &K) != EOF && (N || M || C || K))
    {
        for (int i = 0; i < 300; i++) AdjList[i].clear();
        for (int i = 0; i < 300; i++) Dist[i] = inf;
        for (int i = 0; i < M; i++)
        {
            int U, V, P;
            scanf("%d %d %d", &U, &V, &P);
            AdjList[U].push_back(ii(V, P));
            AdjList[V].push_back(ii(U, P));
            Peso[U][V] = P;
            Peso[V][U] = P;
        }
        Dist[C - 1] = 0;
        for (int i = C - 2; i >= 0; i--)
            Dist[i] = Dist[i + 1] + Peso[i][i + 1];
        priority_queue<ii, vii, greater<ii>> myPQ;
        for (int i = 0; i < N; i++)
            myPQ.push(ii(Dist[i], i));
        while (!myPQ.empty())
        {
            int At = myPQ.top().second;
            myPQ.pop();
            for (ii it : AdjList[At])
            {
                int to = it.first;
                if (to > C - 1)
                {
                    if (Dist[to] > Dist[At] + Peso[At][to])
                    {
                        Dist[to] = Dist[At] + Peso[At][to];
                        myPQ.push(ii(Dist[to], to));
                    }
                }
            }
        }

        printf("%d\n", Dist[K]);
    }
}