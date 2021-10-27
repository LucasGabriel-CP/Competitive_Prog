#include <iostream>

using namespace std;

int main()
{
	int SensorSE, Capac, Ent, Sai,
		Dentro = 0;
	char SensorCap;
	SensorCap = 'N';
	cin >> SensorSE >> Capac;
	for (int i = 0; i < SensorSE; i++)
    {
        cin >> Sai >> Ent;
        Dentro = Dentro + Ent - Sai;
        if (Dentro > Capac)
        SensorCap = 'S';
    }
	cout << SensorCap << '\n';
}