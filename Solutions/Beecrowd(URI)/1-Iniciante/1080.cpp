#include <iostream>

using namespace std;

int main()
{
    int N, MaiorN = 0, Posicao = 0, Y = 0;
    for (int i = 1; i <= 100; i ++)
    {
        cin >> N;
        Y++;
        if (N > MaiorN)
        {
            MaiorN = N;
            Posicao = Y;
        }
    }
        cout << MaiorN << '\n' << Posicao << '\n';
}