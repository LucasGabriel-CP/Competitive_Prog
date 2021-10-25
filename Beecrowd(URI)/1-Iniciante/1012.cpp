#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double A, B, C, T, CI, TRA, Q, R;
	cin >> A >> B >> C;
	cout << fixed << setprecision(3);
	T = A * C / 2;
	CI = C * C * 3.14159;
	TRA = (A + B) / 2 * C;
	Q = B * B;
	R = A * B;
	cout << "TRIANGULO: " << T << "\n"
		<< "CIRCULO: " << CI << "\n"
		<< "TRAPEZIO: " << TRA << "\n"
		<< "QUADRADO: " << Q << "\n"
		<< "RETANGULO: " << R << "\n";
}