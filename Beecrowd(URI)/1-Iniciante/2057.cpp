#include <iostream>

using namespace std;

int main ()
{
    int S, T, F, HoraLocal, HoraReal;
    cin >> S >> T >> F;
    HoraLocal = S + T + F;
    if (HoraLocal >= 24)
    {
        HoraLocal = HoraLocal - 24;
    }
    else if (HoraLocal < 0)
    {
        HoraLocal = HoraLocal + 24;
    }
    cout << HoraLocal << "\n";
}