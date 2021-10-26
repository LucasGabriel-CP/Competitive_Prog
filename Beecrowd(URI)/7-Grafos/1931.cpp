#include <bits/stdc++.h>

using namespace std;

#define sz 50050
#define f first
#define s second
#define inf64 1000000000000000000

typedef pair<int, int> ii;
typedef vector<pair<int, int>> vii;
typedef long long ll;

ll Visit[sz];
vii AdjList[sz];
vii AdjList2[sz];

int x[] = { 0,-1,0,1 }, y[] = { -1,0,1,0 };

int main()
{
    int N, M;
    priority_queue< ii, vii, greater<ii> > myPq;

    scanf("%d %d", &N, &M);
    for (int i = 0; i < sz; i++) Visit[i] = inf64;

    for (int i = 0; i < M; i++)
    {
        int A, B, P; scanf("%d %d %d", &A, &B, &P);
        A--;
        B--;
        AdjList[A].push_back(ii(P, B));
        AdjList[B].push_back(ii(P, A));
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < AdjList[i].size(); j++)
        {
            ii u = AdjList[i][j];
            for (int k = 0; k < AdjList[u.s].size(); k++) {
                if (AdjList[u.s][k].s != i)
                    AdjList2[i].push_back(ii(AdjList[u.s][k].f + u.f, AdjList[u.s][k].s));
            }
        }
    }

    int Com, Fim;
    Com = 0;
    Fim = N - 1;

    myPq.push(ii(0, Com));
    Visit[Com] = 0;
    int Cont = 0;
    while (!myPq.empty())
    {
        ii Fon = myPq.top();
        myPq.pop();
        Cont++;
        for (int i = 0; i < AdjList2[Fon.s].size(); i++)
        {
            ii V = AdjList2[Fon.s][i];
            if (Visit[V.s] > Visit[Fon.s] + V.f)
            {
                Visit[V.s] = Visit[Fon.s] + V.f;
                myPq.push(V);
            }
        }
    }
    printf("%lld\n", Visit[Fim] == inf64 ? -1 : Visit[Fim]);
}