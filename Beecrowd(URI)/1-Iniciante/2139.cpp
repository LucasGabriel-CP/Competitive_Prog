#include <iostream>

using namespace std;

int main()
{
    int M, i, Mes[13], MesAt, Dia,
    TotDias, TotDiaMes;
    for (M = 1; M < 8; M ++)
    {
        if (M == 2)
            Mes[M] = 29;
        else if(M % 2 == 0)
            Mes[M] = 30;
        else
            Mes[M] = 31;
    }
    for (M = 8; M < 12; M++)
    {
        if (M % 2 == 0)
            Mes[M] = 31;
        else
            Mes[M] = 30;
    }	 
    while(cin >> MesAt >> Dia)
    {
        TotDiaMes = 0;
        TotDias = 0;
        if (MesAt == 12)
            TotDias = 25 - Dia;
        else
        {
            for (M = MesAt; M < 12; M++)
            {
                TotDiaMes += Mes[M];
            }
            TotDias = TotDiaMes - Dia + 25;
        }
        if (MesAt == 12 && Dia > 25)
            cout << "Ja passou!" << '\n';
        else if (TotDias == 1)
            cout << "E vespera de natal!" << '\n';
        else
            TotDias == 0 ? (cout << "E natal!" << '\n') :
                            (cout << "Faltam " << TotDias << " dias para o natal!" << '\n');
    }
}