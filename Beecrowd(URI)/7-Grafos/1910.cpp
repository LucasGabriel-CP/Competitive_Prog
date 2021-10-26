#include <bits/stdc++.h>

using namespace std;

#define inf 1000000000

int Visit[100010];

int main()
{
    int N, O, D, K;
    while (scanf("%d %d %d", &O, &D, &K), O || D || K) 
    {
        queue<int> myQueue;
        set<int> Proh;
        for (int i = 0; i < 100010; i++) Visit[i] = inf;
        for (int i = 0; i < K; i++)
        {
            scanf("%d", &N);
            Proh.insert(N);
        }
        myQueue.push(O);
        Visit[O] = 0;
        while (!myQueue.empty())
        {
            int Fon = myQueue.front();
            myQueue.pop();
            if (Fon < 100000)
            {
                int V = Fon + 1;
                if (!Proh.count(V) && Visit[V] > Visit[Fon] + 1)
                {
                    Visit[V] = Visit[Fon] + 1;
                    myQueue.push(V);
                }
            }
            if (Fon > 1)
            {
                int V = Fon - 1;
                if (!Proh.count(V) && Visit[V] > Visit[Fon] + 1)
                {
                    Visit[V] = Visit[Fon] + 1;
                    myQueue.push(V);
                }
            }
            if (Fon % 2 == 0)
            {
                int V = Fon / 2;
                if (!Proh.count(V) && Visit[V] > Visit[Fon] + 1)
                {
                    Visit[V] = Visit[Fon] + 1;
                    myQueue.push(V);
                }
            }
            if (Fon * 2 <= 100000)
            {
                int V = Fon * 2;
                if (!Proh.count(V) && Visit[V] > Visit[Fon] + 1)
                {
                    Visit[V] = Visit[Fon] + 1;
                    myQueue.push(V);
                }
            }
            if (Fon * 3 <= 100000)
            {
                int V = Fon * 3;
                if (!Proh.count(V) && Visit[V] > Visit[Fon] + 1)
                {
                    Visit[V] = Visit[Fon] + 1;
                    myQueue.push(V);
                }
            }
            if (Fon == D)
            {
                while (!myQueue.empty())
                    myQueue.pop();
            }
        }
        if (Visit[D] != inf)
            printf("%d\n", Visit[D]);
        else
            printf("-1\n");
    }
}