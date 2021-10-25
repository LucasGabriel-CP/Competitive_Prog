#include <iostream>
#include <iomanip>

using namespace std;

int main ()
{
    int N, Numero;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> Numero;
        if (Numero == 0)
            cout << "NULL" << '\n';
        if (Numero > 0 && Numero % 2 == 0)
            cout << "EVEN POSITIVE" << '\n';
        else if (Numero > 0 && Numero % 2 != 0)
            cout << "ODD POSITIVE" << '\n';
        else if (Numero < 0 && Numero % 2 == 0)
            cout << "EVEN NEGATIVE" << '\n';
        else if (Numero < 0 && Numero % 2 != 0)
            cout << "ODD NEGATIVE" << '\n';
    }
}