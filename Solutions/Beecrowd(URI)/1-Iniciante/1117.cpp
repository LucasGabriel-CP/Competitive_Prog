#include <iostream>
#include <iomanip>

using namespace std;

int main ()
{
    float Nota1, Nota2, Media;
    do
    {
        cin >> Nota1;
        if (Nota1 < 0 || Nota1 > 10)
        {
            cout << "nota invalida" << '\n';
        }
    } while (Nota1 < 0);
    do
    {
        cin >> Nota2;
        if (Nota2 < 0 || Nota2 >10)
        {
            cout << "nota invalida" << '\n';
        }
    } while (Nota2 < 0 || Nota2 > 10);
    Media = (Nota1 + Nota2) / 2;
    cout << fixed 		<< setprecision(2)
        << "media = "  << Media << '\n';
}