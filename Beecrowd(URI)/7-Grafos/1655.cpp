#include <bits/stdc++.h>

using namespace std;

#define sz 110
#define f first
#define s second

typedef pair<int, double> pid;
typedef vector<pair<int, double>> vid;

int main()
{
    int N, M;
    double Visit[sz];
    while (scanf("%d", &N), N)
    {
        vid AdjList[sz];
        scanf("%d", &M);
        for (int i = 0; i < sz; i++) Visit[i] = -1;
        for (int i = 0; i < M; i++)
        {
            int A, B, P; scanf("%d %d %d", &A, &B, &P);
            A--;
            B--;
            AdjList[A].push_back(pid(B, P * 0.01));
            AdjList[B].push_back(pid(A, P * 0.01));
        }
        priority_queue< pid > myPq;
        myPq.push(pid(0, 0.0));
        Visit[0] = 100;
        while (!myPq.empty())
        {
            pid Fon = myPq.top();
            myPq.pop();
            if (Fon.f < N)
            {
                for (int i = 0; i < AdjList[Fon.f].size(); i++)
                {
                    pid V = AdjList[Fon.f][i];
                    if (Visit[V.f] < Visit[Fon.f] * V.s)
                    {
                        Visit[V.f] = Visit[Fon.f] * V.s;
                        myPq.push(V);
                    }
                }
            }
        }
        printf("%6lf percent\n", Visit[N - 1]);
    }
    return 0;
}