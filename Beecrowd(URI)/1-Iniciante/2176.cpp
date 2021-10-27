#include <iostream>

using namespace std;

void Contagem(string Numero,int *Count)
{
    for(int i = 0; i < Numero.size(); i++)
    {
        if(Numero[i] == '1')
            *Count = *Count + 1;
    }
}

int main()
{
    string Num;
    int Pares = 0;
    cin >> Num;
    Contagem(Num, &Pares);
    if(Pares % 2 == 0)
        cout << Num << "0" << '\n';
    else
        cout << Num << "1" << '\n';
}