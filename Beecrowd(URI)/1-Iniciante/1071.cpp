#include <iostream>

using namespace std;

int SomaImp(int X, int Y, int Soma)
{
    if(X == Y)
        return Soma;
    if(X % 2 != 0)
        Soma += X;
    return SomaImp(X + 1, Y, Soma);
}

int main()
{
    int Num1, Num2;
    cin >> Num1 >> Num2;
    if(Num1 > Num2)
        swap(Num1,Num2);
    if(Num1 == Num2)
        cout << 0 << '\n';
    else
        cout << SomaImp(Num1 + 1, Num2, 0) << '\n';
}