#include <iostream>

using namespace std;

int main()
{
	int Pessoas, k, NDatas,
		Sim, i, j;
	while(cin >> Pessoas >> NDatas)
    {
        int Tururu[NDatas], Pessoa[Pessoas];
        string Data, DataPos[NDatas];
        for (i = 0, k = 0; i < NDatas; i++)
        {
            cin >> Data;
            Sim = 0;
            for(j = 0; j < Pessoas; j++)
            {
                cin >> Pessoa[j];
                if (Pessoa[j] == 1)
                    Sim++;
            }
            if (Sim == Pessoas)
            {
                DataPos[k] = Data;
                Tururu[i] = 1;
                k++;
            }
            else
            Tururu[i] = 0;
        }
        for (i = 0; i < NDatas && Tururu[i] == 0; i++);
        if (Tururu[i] == 1)
        {
            cout << DataPos[0] << '\n';
        }
        else	
            cout << "Pizza antes de FdI" << '\n';
}
}