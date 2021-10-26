#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long int Casos, Numero, Fib[61];
    cin >> Casos;
    for (int i = 0; i < Casos; i++)
    {
        cin >> Numero;
        Fib[0] = 0;
        Fib[1] = 1;
        if (Numero < 2)
        cout << "Fib(" << Numero <<") = " << Fib[Numero] << '\n';
        else if (Numero > 1)
        {
            for (int j = 2; j < 61; j++)
            {
                Fib[j] = Fib[j - 1] + Fib[j - 2];
            }
            cout << "Fib(" << Numero <<") = "
                << Fib[Numero] << '\n';
        }
    }
}