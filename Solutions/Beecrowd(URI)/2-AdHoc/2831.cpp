#include <iostream>

using namespace std;

int main()
{
	int Result = 0, Caixas, i;
	cin >> Caixas;
	long int Caixa[Caixas];
	for(i = 1; i <= Caixas; i++)
    {
        cin >> Caixa[i];
    }
	Caixa[0] = 0;
	for(i = 1; i <= Caixas && Result == 0; i++)
    {
        if(Caixa[i] - Caixa[i -1] > 8 || Caixa[i] - Caixa[i -1] < -8)
            Result = 1;
    }
	if(Result == 1)
		cout << "N" << '\n';
	else
		cout << "S" << '\n';
}