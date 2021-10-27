#include <iostream>

using namespace std;

int Verifica(int *Vet, int Posi1, int Posi2, int Posi3)
{
    int Count = 0;
    if(Vet[Posi1] < Vet[Posi2] && Vet[Posi1] < Vet[Posi3])
        Count++;
    else
        if(Vet[Posi1] > Vet[Posi2] && Vet[Posi1] > Vet[Posi3])
            Count++;
    return Count;
}

int main()
{
    int Picos, NAmostra;
    cin >> NAmostra;
    while(NAmostra != 0)
    {
        int Mag[NAmostra];
        for(int i = 0; i < NAmostra; i++)
            cin >> Mag[i];
        Picos = Verifica(Mag, 0, 1, NAmostra - 1);
        for(int i = 1; i < NAmostra - 1; i++)
        {
            if(Mag[i] < Mag[i - 1] && Mag[i] < Mag[i + 1])
                Picos++;
            else
                if(Mag[i] > Mag[i - 1] && Mag[i] > Mag[i + 1])
                    Picos++;
        }
        Picos += Verifica(Mag, NAmostra - 1, 0, NAmostra - 2);
        cout << Picos << '\n';
        cin >> NAmostra;
    }
}