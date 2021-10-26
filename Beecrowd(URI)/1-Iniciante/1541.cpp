#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int LadoA, LadoB, Percentual, AreaCasa;
    double AreaTerreno, LadoTerreno;
    cin >> LadoA;
    while (LadoA != 0)
    {
        cin >> LadoB >> Percentual;
        AreaCasa = LadoA * LadoB;
        AreaTerreno = AreaCasa / (Percentual / 100.00);
        LadoTerreno = sqrt(AreaTerreno);
        cout << trunc(LadoTerreno) << '\n';
        cin >> LadoA;
    }
}