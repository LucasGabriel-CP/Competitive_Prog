#include <iostream>
#include <iomanip>

using namespace std;

int main ()
{
	char nome[20];
	cin >> nome;
    double S, V, multiplicacao;
    cin >> S >> V;
    multiplicacao = V * 0.15 + S;
    cout << fixed << setprecision(2);
    cout << "TOTAL = R$ " << multiplicacao << "\n";
}