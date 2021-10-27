#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int Inst, i, j, Divisores;
    long long int Num, Resto;
    cin >> Inst;
    for (i = 0; i < Inst; i++)
    {
        cin >> Num;
        Divisores = 0;
        for (j = 1; j <= sqrt(Num); j++)
        {
            Resto = Num % j;
            if (Resto == 0)
            Divisores++;
        }
        if (Divisores == 1)
        cout << "Prime" << '\n';
        else
        cout <<"Not Prime" << '\n';
    }
}