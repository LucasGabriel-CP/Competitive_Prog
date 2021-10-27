#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
    int N, Resultado;
    cin >> N;
    Resultado = 0;
    for (int i = 2; i <= N; i+= 2)
    {
        Resultado = pow(i, 2);
        cout << i << "^2 = "<< Resultado << '\n';
    }
}