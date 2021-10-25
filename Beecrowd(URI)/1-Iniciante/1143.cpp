#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
    int Cubo, N, Quadrado;
    cin >> N;
    Quadrado = 0;
    Cubo     = 0;
    for (int i = 1; i <= N; i++)
    {
        Quadrado = pow(i, 2);
        Cubo     = pow(i, 3);
        cout << i   << " "  << Quadrado
                << " " << Cubo << '\n';
    }
}