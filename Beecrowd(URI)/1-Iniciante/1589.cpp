#include <iostream>

using namespace std;

int main()
{
    int Casos;
    long Raio1, Raio2;
    cin >> Casos;
    for (int i = 0; i < Casos; i++)
    {
        cin >> Raio1 >> Raio2;
        cout << Raio1 + Raio2 << '\n';
    }
}