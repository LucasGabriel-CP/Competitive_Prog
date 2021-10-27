#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int M, Nota, Carga;
	long Somador1, Somador2;
	float Result;
	cout << fixed << setprecision(4);
	
	while(cin >> M)
	{
		Somador1 = Somador2 = 0;
		for(int i = 0; i < M; i++)
		{
			cin >> Nota >> Carga;
			Somador1 += (Nota * Carga);
			Somador2 += Carga;
		}
		Result = Somador1 / (Somador2 * 100.00);
		
		cout << Result << '\n';
	}	
	return 0;
}