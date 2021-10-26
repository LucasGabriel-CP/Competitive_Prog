#include <iostream>

using namespace std;

void Prenche(int *Vet, int Count, int Valor, int Num)
{
    if(Count == 1000)
        return;
    if(Valor == Num)
        Valor = 0;
    Vet[Count] = Valor;
    return Prenche(Vet, Count + 1, Valor + 1, Num);
}

int main()
{
    int Num, Vetor[1000];
    cin >> Num;
    Prenche(Vetor, 0, 0, Num);
    for(int i = 0; i < 1000; i++)
        cout << "N["   << i
                << "] = " << Vetor[i] << '\n';
}