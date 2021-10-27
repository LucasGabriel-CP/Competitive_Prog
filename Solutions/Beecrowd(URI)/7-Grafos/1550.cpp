#include <bits/stdc++.h>

using namespace std;

#define sz 10050
#define inf 1000000000


int Visit[sz];

int revert(int i)
{
    int aux = 0;

    while (i)
    {
        aux *= 10;
        aux += i % 10;
        i /= 10;
    }
    return aux;
}

int main()
{
    int N;	scanf("%d", &N);
    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < sz; i++) Visit[i] = inf;
        int B, A, Fon;
        scanf("%d %d", &A, &B);
        queue< int > myQueue;
        myQueue.push(A);
        Visit[A] = 0;
        Fon = A;
        while (!myQueue.empty() && Fon != B)
        {
            Fon = myQueue.front();
            myQueue.pop();
            if (Fon < sz)
            {
                int V = Fon + 1;
                if (V < sz && Visit[V] > Visit[Fon] + 1)
                {
                    Visit[V] = Visit[Fon] + 1;
                    myQueue.push(V);
                }
                V = revert(Fon);
                if (V < sz && Visit[V] > Visit[Fon] + 1)
                {
                    Visit[V] = Visit[Fon] + 1;
                    myQueue.push(V);
                }
            }
        }

        printf("%d\n", Visit[B]);
    }

    return 0;
}