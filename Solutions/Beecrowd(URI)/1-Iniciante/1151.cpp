#include <iostream>
#include <iomanip>

using namespace std;

int main ()
{
    int Ant = 1, Atual = 1, Numero, Prox;
    cin >> Numero;
    for (int i = 1; i <= Numero; i++)
    {
        if (i == 1)
            cout << "0";
        else if (i == 2 || i == 3)
            cout << " 1";
        else
        {
            Prox  = Ant + Atual;
            Ant   = Atual;
            Atual = Prox;
            cout << " " << Prox;
        }
    }
    cout << "\n";
}