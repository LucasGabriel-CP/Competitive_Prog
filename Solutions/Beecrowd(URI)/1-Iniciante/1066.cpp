#include <iostream>
#include <iomanip>

using namespace std;

int main ()
{
    int N, Par, Impar, Positivo, Negativo;
    Par = 0;
    Impar = 0;
    Positivo = 0;
    Negativo = 0;
    for (int i = 0; i < 5; i++)
    {
        cin >> N;
        if (N % 2 == 0)
            Par++;
        else 
            Impar++;
        if (N > 0)
            Positivo++;
        else if (N < 0)
            Negativo++;
    }
    cout << Par      << " valor(es) par(es)"     << "\n" 
        << Impar    << " valor(es) impar(es)"   << "\n"
        << Positivo << " valor(es) positivo(s)" << "\n" 
        << Negativo << " valor(es) negativo(s)" << "\n";
}