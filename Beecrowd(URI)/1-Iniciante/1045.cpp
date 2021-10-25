#include <iostream>

using namespace std;

int main()
{
    double A, B, C;
    cin >> A >> B >> C;
    if(A >= (B + C) || B >= (A + C) || C >= (A + B))
        cout << "NAO FORMA TRIANGULO" << "\n";
    else if(A * A == (B * B + C * C) || B * B == (A * A + C * C) || C * C == (A * A + B * B))
        cout << "TRIANGULO RETANGULO" << "\n";
    else if(A * A > (B * B + C * C) || B * B > (A * A + C * C) || C * C > (A * A + B * B))
        cout << "TRIANGULO OBTUSANGULO" << "\n";
    else if(A * A < (B * B + C * C) || B * B < (A * A + C * C) || C * C < (A * A + B * B))
        cout << "TRIANGULO ACUTANGULO" << "\n";
    if(A == B && A == C)
        cout << "TRIANGULO EQUILATERO" << "\n";
    if((A == B && A != C)  || (A == C && A != B) || (B == C && B != A))
        cout << "TRIANGULO ISOSCELES" << "\n";
}