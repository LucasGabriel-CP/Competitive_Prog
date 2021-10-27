#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int Casos, Num;
	long Soma;
	cin >> Casos;
	for(int i = 0; i < Casos; i++)
	{
		cin >> Num;
		
		Soma = 0;
		for(int j = 0; j < Num; j++)
			Soma += pow(2, j);
		cout << Soma << '\n';
	}
		
	return 0;
}