#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    float M[12][12], Soma = 0.0;
    int Coluna;
    char Opcao;
    cout << fixed << setprecision(1);
    cin >> Coluna >> Opcao;
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            cin >> M[i][j];
            if (j == Coluna)
                Soma += M[i][j];
        }
    }
    if (Opcao == 'S')
        cout << Soma << '\n';
    else if (Opcao == 'M')
        cout << Soma / 12.0 << '\n';
}