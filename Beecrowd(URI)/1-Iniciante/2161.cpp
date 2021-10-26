#include <iostream>
#include <iomanip>

using namespace std;
double Repet(double X, int Y);

int main()
{
    double Resultado, Denominador;
    int NRept;
    cout << fixed << setprecision(10);
    cin >> NRept;
    Denominador = 1.00 / 6;
    if (NRept == 0)
        cout << 3.0000000000 << '\n';
    else
    {
        Resultado = 3.0000000000 + Repet(Denominador, NRept);
        cout << Resultado << '\n';
    }
}

double Repet(double X, int Y)
{
    for(int i = 1; i < Y; i++)
    {
        X = 1.00 / (X + 6);
    }
    return X;
}