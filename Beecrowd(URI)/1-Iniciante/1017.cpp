#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double h, km_h, km, litros;
    cin >> h >> km_h;
    km = km_h * h;
    litros = km / 12;
    cout << fixed << setprecision(3);
    cout << litros << "\n";
}