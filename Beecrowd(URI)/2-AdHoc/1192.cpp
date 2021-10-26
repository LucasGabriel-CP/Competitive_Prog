#include <iostream>

using namespace std;

int main()
{
    int Casos, Aux, Num1, Num2, Resultado;
    char Letra;
    cin >> Casos;
    for (int i = 0; i < Casos; i++)
    {
        cin >> Num1;
        cin >> Letra;
        cin >> Num2;
        Aux = int(Letra);
        if (Num1 == Num2)
        Resultado = Num1 * Num2;
        else if (Aux >= 65 && Aux <= 90)
        Resultado = Num2 - Num1;
        else if (Aux >= 97 && Aux <= 122)
        Resultado = Num1 + Num2;
        cout << Resultado << '\n';
    }
}