#include <iostream>

using namespace std;

int main()
{
	int VolumIn, Mudancas, Modificacao;
	cin >> VolumIn >> Mudancas;
	int VolumFi = VolumIn;
	for (int i = 0; i < Mudancas; i++)
        {
            cin >> Modificacao;
            VolumFi += Modificacao;
            if (VolumFi > 100)
                VolumFi = 100;
            if (VolumFi < 0)
                VolumFi = 0;
        }
	cout << VolumFi << '\n';
}