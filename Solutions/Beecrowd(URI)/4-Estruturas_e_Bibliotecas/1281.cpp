#include <iostream>
#include <string.h>
#include <iomanip>
#include <map>

using namespace std;

int main() 
{
	float Preco;
	int N, M, P, Qnt;
	string Fruta;

	cout << fixed << setprecision(2);
	cin >> N;
	for	(int i = 0; i < N; i++)
	{
		map< string,float > mymap;
		float Sum = 0.00;
		cin >> M;
		for	(int j = 0; j < M; j++)
		{
			cin >> Fruta >> Preco;
			mymap[Fruta] = Preco;
		}
		cin >> P;
		for	(int j = 0; j < P; j++)
		{
			cin >> Fruta >> Qnt;
			Sum += mymap[Fruta] * Qnt;
		}
		cout << "R$ " << Sum << '\n';
	}
}