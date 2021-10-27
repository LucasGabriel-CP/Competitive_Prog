#include <iostream>

using namespace std;

int main ()
{
    int Anos, T, PA, PB;
    float CresA, CresB;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        Anos = 0;
        cin >> PA >> PB >> CresA >> CresB;
        while (PB >= PA && Anos <= 100)
        {
            PA = PA + (PA * CresA) / 100;
            PB = PB + (PB * CresB ) / 100;
            Anos++;
        }
        if (Anos > 100)
            cout << "Mais de 1 seculo." << '\n';
        else 
            cout << Anos << " anos." << '\n';
    }
}