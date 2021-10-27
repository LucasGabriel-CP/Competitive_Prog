#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double A, B, C, multiplicacao;
    cout << fixed << setprecision(1);
    cin >> A >> B >> C;
    multiplicacao = A * 0.2 + B * 0.3 + C * 0.5;
    cout << "MEDIA = " << multiplicacao << "\n";
}