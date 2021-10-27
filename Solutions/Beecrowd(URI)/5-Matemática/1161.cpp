#include <iostream>

using namespace std;
long long int Fatorial(long long int X, long long int Y);

int main()
{
    long long int Num1, Num2, i,
                Fat1, Fat2, Soma;
    while(cin >> Num1 >> Num2)
    {
        if (Num1 == 0)
            Fat1 = 1;
        else
        {
            Fat1 = Num1;
            Fat1 = Fatorial(Num1, Fat1);
        }
        if (Num2 == 0)
            Fat2 = 1;
        else
        {
            Fat2 = Num2;
            Fat2 = Fatorial(Num2, Fat2);		 	
        }
        Soma = Fat1 + Fat2;
        cout << Soma << '\n';
    }
}

long long int Fatorial(long long int X, long long int Y)
{
    long long int i;
    for(i = X; i > 1; i--)
    {
        Y *= (i - 1);
    }
    return Y;
}