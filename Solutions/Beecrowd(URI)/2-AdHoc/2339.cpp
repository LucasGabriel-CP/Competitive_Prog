#include <iostream>

using namespace std;

int main()
{
	int C, P, F, multiplicacao;
	cin >> C >> P >> F;
	multiplicacao = C * F;
	if (multiplicacao <= P) {
	    cout << "S" << "\n";
	}
	else if (multiplicacao) {
		cout << "N" << "\n";
	}
}