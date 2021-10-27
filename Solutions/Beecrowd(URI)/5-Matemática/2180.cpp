#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int Divisores, Peso, Resto,
        TempoDias, TempoHoras,
        Parada = 0, SomaPrimos = 0;

    cin >> Peso;
    for (int i = Peso; Parada < 10; i++)
    {
        Divisores = 0;
        for (int j = 1; j <= sqrt(i); j++)
        {
            Resto = i % j;
            if (Resto == 0)
            Divisores++;
        }
        if (Divisores == 1)
        {
            SomaPrimos += i;
            Parada++;
        }
    }

    TempoHoras = 60000000 / SomaPrimos;
    TempoDias  = TempoHoras / 24;

    cout << SomaPrimos << " km/h" << '\n'
            << TempoHoras << " h / "
            << TempoDias  << " d"    << '\n';

    return 0;
}