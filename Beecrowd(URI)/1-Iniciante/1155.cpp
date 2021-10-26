#include <iostream>
#include <iomanip>

using namespace std;

int main ()
{
    float S, Aux;
    S = 0;
    for (double i = 1; i <= 100; i++)
    {
        Aux = 1 / i;
        S   = S + Aux;	
    }
    cout << fixed << setprecision(2)
        << S     << '\n';
}