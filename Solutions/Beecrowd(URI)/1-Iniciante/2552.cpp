#include <iostream>

using namespace std;

int main()
{
	int N, M, i, j, Pao;
	while (cin >> N >> M)
    {
        double Matriz[N][M];
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < M; j++)
            {
                cin >> Matriz[i][j];
            }
        }
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < M; j++)
            {
                if (Matriz[i][j] == 1)
                Matriz[i][j] = 9;
            }
        }
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < M; j++)
            {
                if (Matriz[i][j] != 9)
                {
                    Pao = 0;
                    if (i > 0 && Matriz[i - 1][j] == 9)
                        Pao++;
                    if (i < N && Matriz[i + 1][j] == 9)
                        Pao++;
                    if (j > 0 && Matriz[i][j - 1] == 9)
                        Pao++;
                    if (j < M - 1 && Matriz[i][j + 1] == 9)
                        Pao++;
                    Matriz[i][j] = Pao;
                }
            }
        }
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < M; j++)
            {
                cout << Matriz[i][j];
            }
            cout << '\n';
        }
    }
}