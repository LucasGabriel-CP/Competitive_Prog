#include <iostream>
#include <algorithm> 

using namespace std;

int main()
{
    int Quant, Soma;
    cin >> Quant;
    int Valor[Quant];
    for (int i = 0; i < Quant; i++)
        cin >> Valor[i];
    sort (Valor, Valor + Quant);
    for (int i = 0; i < Quant; i++)
    {
        if (i == 0)
        {
            Soma = 1;
            for (int j = i + 1; j < Quant && Valor[i] == Valor[j]; j++)
                Soma++;
            cout << Valor[i] << " aparece " << Soma << " vez(es)" << '\n';
        }
        else
            if (i > 0 && Valor[i] != Valor[i - 1])
            {
                Soma = 1;
                for (int j = i + 1; j < Quant && Valor[i] == Valor[j]; j++)
                    Soma++;
                cout << Valor[i] << " aparece " << Soma << " vez(es)" << '\n';
            }
    }
}