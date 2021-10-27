#include <iostream>

using namespace std;

int main()
{
	int Largura, Comprimento,
		Medida1, Medida2;
	cin >> Largura >> Comprimento;
	Medida1 = Comprimento * Largura + (Comprimento - 1) * (Largura - 1);
	Medida2 = (Comprimento - 1) * 2 + (Largura - 1) * 2;
	cout << Medida1 << '\n'
		 << Medida2 << '\n';

	return 0;
}