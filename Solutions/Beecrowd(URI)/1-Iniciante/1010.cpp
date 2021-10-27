#include <iostream>
#include <iomanip>

using namespace std;

int main ()
{
    double a, b, c, d, e, f, multiplicacao;
    cout << fixed << setprecision(2);
    cin >> a >> b >> c 
    >> d >> e >> f; 
    multiplicacao = b * c + e * f;
    cout << "VALOR A PAGAR: R$ " << multiplicacao << "\n";
}