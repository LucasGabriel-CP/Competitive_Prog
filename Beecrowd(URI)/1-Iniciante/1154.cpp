#include <iostream>
#include <iomanip>

using namespace std;

int main ()
{
    int N, Soma = 0, Quantidade = 0;
    float Media;
    cin >> N;
    while(N >= 0)
    {
        if (N >= 0)
        {
            Soma += N;
            Quantidade++;
        }
        cin >> N;
    } 
    Media = (float)Soma/Quantidade;
    cout << fixed << setprecision(2) 
        << Media << '\n';
}