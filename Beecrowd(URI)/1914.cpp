#include <iostream>

using namespace std;

int main()
{
    int Teste, Num1, Num2,
        Soma = 0;
    string Jog1, Jog2,
         Esc1,   Esc2;
    cin >> Teste;
    for (int i = 0; i < Teste; i++)
    {
        cin >> Jog1 >> Esc1
            >> Jog2 >> Esc2
            >> Num1 >> Num2;
        Soma = Num1 + Num2;
        if (Soma % 2 == 0)
        {
            if (Esc1 == "PAR")
                cout << Jog1 << '\n';
            else if (Esc2 == "PAR")
                cout << Jog2 << '\n';
        }
        else if (Soma % 2 != 0)
        {
            if (Esc1 == "IMPAR")
                cout << Jog1 << '\n';
            else if (Esc2 == "IMPAR")
                cout << Jog2 << '\n';
        }
    }
}