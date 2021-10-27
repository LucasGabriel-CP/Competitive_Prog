#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int Num, i,
    Menor, Posicao = 0;
    cin >> Num;
    int Vec[Num];
    for (i = 0; i < Num; i++)
    {
        cin >> Vec[i];
    }
    Menor = Vec[0];
    for (i = 0; i < Num; i++)
    {
        if (Vec[i] < Menor)
        {
            Menor = Vec[i];
            Posicao = i;
        }
    }
    cout << "Menor valor: " << Menor   << '\n'
        << "Posicao: "		<< Posicao << '\n';
}