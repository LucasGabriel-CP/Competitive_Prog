#include <cstdio>
#include <stack>

using namespace std;

int main()
{
    int N, Aux, Vag[1010];
    while(scanf("%d", &N) && N)
    {
        while (scanf("%d", &Vag[0]) && Vag[0])
        {
            for (int i = 1; i < N; i++)
                scanf("%d", &Vag[i]);
            Aux = 0;
            stack<int> Estacao;
            for (int i = 1; i <= N; i++)
            {
                Estacao.push(i);
                while(!Estacao.empty() && Estacao.top() == Vag[Aux])
                {
                    Estacao.pop();
                    Aux++;
                }
            }
        if  (Aux == N)
            printf("Yes\n");
        else
            printf("No\n");
        }
        printf("\n");
    }
}