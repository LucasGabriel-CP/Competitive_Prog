#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() 
{
    int A, B, multiplo, multiplo2;
    cin >> A >> B;
    multiplo = B % A;
    multiplo2 = A % B;
    if (multiplo == 0 || multiplo2 == 0) 
        cout << "Sao Multiplos" << "\n";
    else
        cout << "Nao sao Multiplos" << "\n";
}