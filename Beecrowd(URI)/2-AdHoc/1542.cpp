#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float Q, D, P, Result;
    cin >> Q;
    while (Q != 0)
    {
        cin >> D >> P;
        Result = (Q * D) / (P - Q) * P;
        if (Result >= 2 || Result <= -2)
            cout << trunc(Result) << " paginas" << '\n';
        else
            cout << trunc(Result) << " pagina" << '\n';
        cin >> Q;
    }
}