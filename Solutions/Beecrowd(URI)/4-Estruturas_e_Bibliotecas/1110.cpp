#include <cstdio>
#include <queue>

using namespace std;

int main()
{
    int N, Count, Vet[60];
    while(scanf("%d", &N) != EOF && N)
    {		
        Count = 0;
        queue<int> Cartas;
        for (int i = 1; i <= N; i++)
            Cartas.push(i);
        while (Cartas.size() > 1)
        {
            Vet[Count] = Cartas.front();
            Cartas.pop();
            
            Cartas.push(Cartas.front());
            Cartas.pop();
            
            Count++;
        }
        printf("Discarded cards:");
        for (int i = 0; i < Count - 1; i++)
            printf(" %d,", Vet[i]);
        if  (Count > 0)
            printf(" %d", Vet[Count - 1]);
        printf("\nRemaining card: %d\n", Cartas.front());
    }
}