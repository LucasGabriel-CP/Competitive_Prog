#include <iostream>

using namespace std;

int main ()
{
    int Inicio, Fim;
    cin >> Inicio >> Fim;
    if (Inicio == Fim)
        cout << "O JOGO DUROU 24 HORA(S)" << "\n";
    else if (Inicio == 0 && Fim <= 12)  
        cout << "O JOGO DUROU " << Fim << " HORA(S)" << "\n";
    else if (Inicio == 0 && Fim > 12) 
        cout << "O JOGO DUROU " << 24 - Fim << " HORA(S)" << "\n";
    else if (Inicio != 0 && Fim == 0) 
        cout << "O JOGO DUROU " << 24 - Inicio << " HORA(S)" << "\n";
    else if (Inicio > Fim) 
        cout << "O JOGO DUROU " << 24 - Inicio + Fim << " HORA(S)" << "\n";
    else if (Inicio < Fim) 
        cout << "O JOGO DUROU " << Fim - Inicio << " HORA(S)" << "\n";
}