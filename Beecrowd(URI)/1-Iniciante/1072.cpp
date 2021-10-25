#include <iostream>

using namespace std;

int main ()
{
    int Dentro, Fora, N, X;
    Dentro = 0;
    Fora   = 0;
    N      = 0;
    X      = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> X;
        if (X >= 10 && X <=20)
            Dentro++;
        else
            Fora++;
    }
    cout << Dentro << " in"  << '\n'
            << Fora   << " out" << '\n';
}