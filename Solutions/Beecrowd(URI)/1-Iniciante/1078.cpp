#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
    int N, Resultado;
    cin >> N;
    Resultado = 0;
    for (int i = 1; i <= 10; i++)
    {
        Resultado = i * N;
        cout << i << " x " << N << " = "
        << Resultado << '\n';
    }
}