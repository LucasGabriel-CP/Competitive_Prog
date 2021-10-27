#include <iostream>

using namespace std;

int main()
{
    int A, B, C, D, soma1, soma2;
    cin >> A >> B >> C >> D;
    soma1 = C + D;
    soma2 = A + B;
    if (B > C && D > A && soma1 > soma2 && C > 0 && D > 0 && A % 2 == 0)
    {
        cout << "Valores aceitos" << "\n";
    }
    else 
    {
        cout << "Valores nao aceitos" << "\n";
    }
}