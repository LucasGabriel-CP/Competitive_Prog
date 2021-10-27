#include <iostream>

using namespace std;

int main()
{
    int N, i, j, Aux;
    while(cin >> N)
    {
        Aux = N;
        double Matriz[N][N];
        for (i = 0; i < N; i++)
        {
            Aux--;
            for (j = 0; j < N; j++)
            {
                if (j == Aux)
                Matriz[i][j] = 2;
                else if (j == i)
                Matriz[i][j] = 1;
                else
                Matriz[i][j] = 3;
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
    }
}