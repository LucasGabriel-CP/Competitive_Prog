#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int Casos, X, Y,
    Rafa, Beto, Carlos;
    cin >> Casos;
    for(int i = 0; i < Casos; i++)
    {
        cin >> X >> Y;
        Rafa = pow((3 * X), 2) + pow(Y, 2);
        Beto = 2 * pow(X, 2) + pow((5 * Y), 2);
        Carlos = -100 * X + pow(Y, 3);
        if(Rafa > Beto && Rafa > Carlos)
            cout << "Rafael ganhou" << '\n';
        else if(Beto > Rafa && Beto > Carlos)
            cout << "Beto ganhou" << '\n';
        else if(Carlos > Beto && Carlos > Rafa)
            cout << "Carlos ganhou" << '\n';
    }
}