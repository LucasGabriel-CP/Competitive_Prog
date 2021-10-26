#include <iostream>

using namespace std;

int main()
{
    long int Casos;
    string Num1, Num2, Numero1;
    cin >> Casos;
    for(int i = 0; i < Casos; i++)
    {
        Numero1 = "";
        cin >> Num1 >> Num2;
        for(int j = Num1.size() - Num2.size(); j < Num1.size(); j++)
        {
            Numero1 += Num1[j];
        }
        if (Numero1 != Num2)
            cout << "nao encaixa" << '\n';
        else
            cout << "encaixa" << '\n';
    }
}