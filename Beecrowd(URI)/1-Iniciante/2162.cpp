#include <iostream>

using namespace std;

int main()
{
    int i, Medidas, Resultado = 0;
    cin >> Medidas;
    int Altura [Medidas];
    for ( i = 0; i < Medidas; i++)
    {
        cin >> Altura[i];
    }
    if (Medidas == 2 && Altura[0] != Altura[1])
        Resultado = 1;
    else
    {
        for (i = 1; i < Medidas - 1; i++)
        {
            if(Altura[i] > Altura[i - 1] && Altura[i] < Altura [i + 1])
            {
                Resultado = 0; break;
            }
            if(Altura[i] < Altura[i - 1] && Altura[i] > Altura [i + 1])
            {
                Resultado = 0; break;
            }
            if (Altura[i] == Altura [i - 1] || Altura[i] == Altura[i + 1])
            {
                Resultado = 0; break;
            }
            else 
                1Resultado = 1;
        }
    }
    cout << Resultado << '\n';
}