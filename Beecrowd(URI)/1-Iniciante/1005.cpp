#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double A, B, multiplicacao, divisao;
    cout << fixed << setprecision(5);
    cin >> A >> B;
    multiplicacao = A * 3.5 + B * 7.5;
    divisao = multiplicacao / 11;
    cout << "MEDIA = " << divisao << "\n";
}