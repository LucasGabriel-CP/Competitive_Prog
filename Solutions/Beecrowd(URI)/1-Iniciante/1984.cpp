#include <iostream>

using namespace std;

void Inverter(string Antes, string *Depois)
{
    for(int i = Antes.size() - 1; i >= 0; i--)
    {
        *Depois = *Depois + Antes[i];
    }
}

int main()
{
    string Numero, Inverso = "";
    cin >> Numero;
    Inverter(Numero, &Inverso);
    cout << Inverso << '\n';
}