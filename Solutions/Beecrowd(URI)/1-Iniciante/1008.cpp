#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double F,H,S,multiplicacao;
	cin >> F >> H >> S;
	multiplicacao = H * S;
	cout << "NUMBER = " << F << "\n";
	cout << fixed << setprecision(2);
	cout << "SALARY = U$ " << multiplicacao << "\n";
}