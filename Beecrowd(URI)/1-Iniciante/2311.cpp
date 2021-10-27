#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	float Grau, NComp, N1, N2, N3,
		  N4,   N5,    N6, N7, NotaFinal, 
		  Maior,   Menor;
	cout << fixed << setprecision(2);
	char Nome [30];
	cin >> NComp;
	for (int i = 0; i < NComp; i++)
    {
        Maior = -1,   Menor = 11;
        cin >> Nome >> Grau >> N1 >> N2 >> N3
            >> N4	 >> N5	 >> N6 >> N7;
        /*Sim, uma bosta isso, mas foi no começo que eu fiz*/
        if (N1 > Maior)
            Maior = N1;
        if (N2 > Maior)
            Maior = N2;
        if (N3 > Maior)
            Maior = N3;
        if (N4 > Maior)
            Maior = N4;
        if (N5 > Maior)
            Maior = N5;
        if (N6 > Maior)
            Maior = N6;
        if (N7 > Maior)
            Maior = N7;
        if (N1 < Menor)
            Menor = N1;
        if (N2 < Menor)
            Menor = N2;
        if (N3 < Menor)
            Menor = N3;
        if (N4 < Menor)
            Menor = N4;
        if (N5 < Menor)
            Menor = N5;
        if (N6 < Menor)
            Menor = N6;
        if (N7 < Menor)
            Menor = N7;
        NotaFinal = (N1 + N2 + N3 + N4 + N5 + 
                    N6 + N7 - Maior - Menor) * Grau;
        cout << Nome << " " << NotaFinal << '\n';
    }
}