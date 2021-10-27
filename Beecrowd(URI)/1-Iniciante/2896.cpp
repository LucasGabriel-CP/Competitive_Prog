#include <iostream>

using namespace std;

int main()
{
	int NCas, NRefri, Tes,
		TCas = 0;
	cin >> Tes;
	for (int i = 0; i < Tes; i++)
    {
        cin >> NRefri >> NCas;
        TCas = (NRefri % NCas) + (NRefri / NCas);
        cout << TCas << '\n';
    }
}