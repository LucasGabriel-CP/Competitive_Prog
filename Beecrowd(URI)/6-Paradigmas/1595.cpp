#include <bits/stdc++.h>

using namespace std;

typedef vector< int > vi;

int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        int N, C, M; scanf("%d %d %d", &N, &C, &M);
        vi Andares(N + 1, 0);
        priority_queue<int, vi, greater<int>> myPq;
        for (int i = 0; i < N; i++)
        {
            int Val; scanf("%d", &Val);
            myPq.push(Val);
        }

        double Soma = 0;
        for (int i = 0; i < C && !myPq.empty(); i++, myPq.pop())
            Soma += (1.00 / (myPq.top() + M));
        N -= C;
        for (int i = 0; i < N && !myPq.empty(); i++, myPq.pop())
        {
            Soma += (1.00 / myPq.top());
        }

        printf("%.2lf\n", Soma);
    }

    return 0;
}