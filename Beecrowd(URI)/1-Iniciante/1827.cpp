#include <iostream>

using namespace std;

int main()
{
    int N, i, j, Aux, Parada;
    while(cin >> N)
    {
        Parada = (int)N / 1.5 ;
        if (N % 3 == 0)
        Parada--;
        Aux = N;
        double Matriz[N][N];
        for (i = 0; i < N; i++)
        {
            Aux--;
            for (j = 0; j < N; j++)
            {
                if (j != i)
                Matriz[i][j] = 0;
                if (j == i)
                Matriz[i][j] = 2;
                if (j == Aux)
                Matriz[i][j] = 3;
                if (i >= N / 3 && j >= N / 3 && i <= Parada && j <= Parada)
                Matriz[i][j] = 1;
                if (i == N / 2 && j == N /2)
                Matriz[i][j] = 4;
            }
        }
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
            {
                cout << Matriz[i][j];
                if (j == N - 1)
                cout << '\n';
            }
        }
        cout << '\n';
    }
}