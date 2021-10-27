#include <iostream>

using namespace std;

int main()
{
	int Bandejas, Latas, Copos,
		Quebrados = 0;
	
	cin >> Bandejas;
	for(int i = 0; i < Bandejas; i++)
	{
		cin >> Latas >> Copos;
		if(Latas > Copos)
			Quebrados += Copos;
	}
	cout << Quebrados << '\n';

	return 0;
}