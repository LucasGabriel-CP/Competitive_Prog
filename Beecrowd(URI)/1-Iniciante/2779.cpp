#include <iostream>

using namespace std;

int main()
{
	int Compradas, NumTot, Fig[301],
		Result, Soma = 0;
	bool Parar;
	
	cin >> NumTot >> Compradas;
	
	for(int i = 0; i < Compradas; i++)
		cin >> Fig[i];
		
	for(int i = 0; i < Compradas; i++)
	{
		Parar = false;
		for(int j = 0; j < i && Parar == false; j++)
		{
			if(Fig[i] == Fig[j])
				Parar = true;
		}
		if(Parar == false)
			Soma++;
	}
	
	Result = NumTot - Soma;
	cout << Result << '\n';
	
	return 0;
}