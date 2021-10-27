#include <iostream>

using namespace std;

int main()
{
	int NAtributos, QntM, QntL,
		EscM, EscL, Sorteado, i, j;
	while (cin >> NAtributos)
    {
        cin >> QntM >> QntL;
        long long int AtributoM[QntM][NAtributos], AtributoL[QntL][NAtributos];
        for (i = 0; i < QntM; i++)
        {
            for (j = 0; j < NAtributos; j++)
            {
                cin >> AtributoM[i][j];
            }
        }
        for (i = 0; i < QntL; i++)
        {
            for (j = 0; j < NAtributos; j++)
            {
                cin >> AtributoL[i][j];
            }
        }
        cin >> EscM >> EscL >> Sorteado;		 
        if (AtributoM[EscM - 1][Sorteado - 1] > AtributoL[EscL - 1][Sorteado - 1])
            cout << "Marcos" << '\n';
        else if (AtributoM[EscM - 1][Sorteado - 1] < AtributoL[EscL - 1][Sorteado - 1])
            cout << "Leonardo" << '\n';
        else
            cout << "Empate" << '\n';
    }
}