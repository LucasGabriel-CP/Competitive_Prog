#include <iostream>
#include <cmath>

using namespace std;

int Dobra(int Op, int Dobras, int Aux)
{
	if  (Op == 0)
		return Dobras = pow(Dobras, 2);
	return Dobra(Op - 1, Dobras + Aux, Aux * 2);
}

int main()
{
	int i = 0, N, Result;
	cin >> N;
	while (N > -1)
	{
		i++;
		Result = Dobra(N, 2, 1);
		cout << "Teste " << i << '\n'
			 << Result   << "\n\n";
		cin  >> N;
	}
}