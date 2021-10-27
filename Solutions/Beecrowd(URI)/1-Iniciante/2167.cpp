#include <iostream>

using namespace std;

int main()
{
    int Medidas, i;
    cin >> Medidas;
    int RPM[Medidas], Parada[Medidas];
    for (i = 0; i < Medidas; i++)
    {
        cin >> RPM[i];
    }
    for(i = 0; i < Medidas && RPM[i] >= RPM[i - 1]; i++);
    if( i < Medidas )
        cout << i + 1 << '\n';
    else
         cout << 0 << '\n';
}