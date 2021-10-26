#include <iostream>

using namespace std;

int main()
{
    int Testes;
    long long int Ano, Resultado;
    cin >> Testes;
    for(int i = 0; i < Testes; i++)
    {
        cin >> Ano;
        Resultado = 2015 - Ano;
        if (Resultado == 0)
        cout << "1 A.C." << '\n';
        else if (Resultado < 0)
        {
            Resultado--;
            cout << Resultado * - 1 << " A.C." << '\n';
        }
        else
        cout << Resultado << " D.C." << '\n';
    }
}