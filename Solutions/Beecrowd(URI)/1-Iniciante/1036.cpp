#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    double A, B, C, delta, R1, R2;
    cin >> A >> B >> C;
    delta = pow(B, 2) - 4 * A * C;
    if (A <= 0 || delta <= 0)
    {
        cout << "Impossivel calcular" << "\n";
    }
    else
    {
        R1 = (-B + pow(delta, 0.5)) / (2 * A);
        R2 = (-B - pow(delta, 0.5)) / (2 * A);
        cout << fixed << setprecision(5);
        cout << "R1 = " << R1 << "\n"
            << "R2 = " << R2 << "\n";
    }
}