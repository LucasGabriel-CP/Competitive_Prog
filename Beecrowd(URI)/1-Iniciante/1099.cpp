#include <iostream>

using namespace std;
int Primos(int *X, int Y);

int main()
{
    int Casos, Num1, Num2,
        P, j, SomaPri;
    cin >> Casos;
    for(int i = 0; i < Casos; i++)
    {
        cin >> Num1 >> Num2;
        if (Num1 > Num2)
        swap(Num1, Num2);
        int Primo[Num2 - Num1];
        for(j = Num1 + 1, P = 0; j < Num2; j++)
        {
            if(j % 2 != 0)
            {
                Primo[P] = j;
                P++;
            }
        }
        SomaPri = Primos(Primo, P);
        cout << SomaPri << '\n';
    }
}

int Primos(int *X, int Y)
{
    int Soma = 0;
    for(int i = 0; i < Y; i++)
        Soma += X[i];
    return Soma;
}