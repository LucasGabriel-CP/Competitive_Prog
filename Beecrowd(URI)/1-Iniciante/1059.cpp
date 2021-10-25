#include <iostream>

using namespace std;

void Pares(int *Numeros, int Count, int Aux)
{
    if(Count > 100)
        return;
    if(Count % 2 == 0)
    {
        Numeros[Aux] = Count;
        Aux++;
    }
    return Pares(Numeros, Count + 1, Aux);
}

int main()
{
    int Numeros[50];
    Pares(Numeros, 1, 0);
    for(int i = 0; i < 50; i++)
        cout << Numeros[i] << '\n';
}