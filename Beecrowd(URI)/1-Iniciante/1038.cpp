#include <iostream>
#include <iomanip>

using namespace std;

int main ()	
{
    int codigo;
    float quantidade, valor, total;
    cout << fixed  << setprecision(2);
    cin  >> codigo >> quantidade;
    switch (codigo) 
    {
        case 1: valor = 4;
            break;
        case 2: valor = 4.50;
            break;
        case 3: valor = 5;
            break;
        case 4: valor = 2;
            break;
        case 5: valor = 1.50;
            break;
    }
    total = valor * quantidade;
    cout << "Total: R$ " << total << "\n";
}