#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main ()
{
    float Vol, Diam,
        Altura, Area;
    while(cin >> Vol >> Diam)
    {
        Altura = Vol / (3.14 * pow(Diam / 2, 2));
        Area = 3.14 * pow (Diam / 2, 2);
        cout << fixed << setprecision(2);
        cout << "ALTURA = " << Altura << '\n'
            << "AREA = "	 << Area   << '\n';
    }
}