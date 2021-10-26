#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    float M[12][12], Soma = 0.0;
    char Opcao;
    int Aux = 12;
    cout << fixed << setprecision(1);
    cin >> Opcao;
    for (int i = 0; i < 12; i++)
    {
        Aux--;
        for (int j = 0; j < 12; j++)
        {
            cin >> M[i][j];
            if (j < Aux)
                Soma += M[i][j];
        }
    }
    if (Opcao == 'S')
        cout << Soma << '\n';
    else if (Opcao == 'M')
        cout << Soma / 66 << '\n';
}