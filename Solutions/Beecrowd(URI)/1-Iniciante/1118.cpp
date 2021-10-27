#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    float Nota1, Nota2, Media;
    int Repetir = 1;
    cout << fixed << setprecision(2);
    while(Repetir == 1)
    {
        Nota1 = 0.00;
        Nota2 = 0.00;
        Media = 0.00;
        cin >> Nota1;
        while(Nota1 < 0 || Nota1 > 10)
        {
            cout << "nota invalida" << '\n';
            cin >> Nota1;
        }
        cin >> Nota2;
        while(Nota2 < 0 || Nota2 > 10)
        {
            cout << "nota invalida" << '\n';
            cin >> Nota2;
        }
        Media = (Nota1 + Nota2) / 2;
        cout << "media = " << Media << '\n'
            << "novo calculo (1-sim 2-nao)" << '\n';
        cin >> Repetir;
        while(Repetir < 1 || Repetir > 2)
        {
            cout << "novo calculo (1-sim 2-nao)" << '\n';
            cin >> Repetir;
        }
    }
}