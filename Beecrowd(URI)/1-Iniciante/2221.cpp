#include <iostream>

using namespace std;
int ValorGolpe(int X, int Y, int Z);

int main()
{
	int AtkDa, AtkGu, Bonus, DefDa,
		DefGu, Inst,  LvDa,  LvGu;
	cin >> Inst;
	for (int i = 0; i < Inst; i++)
    {
        int BonusDa = 0,  BonusGu = 0,
        ValorGolpeDa = 0, ValorGolpeGu = 0;
        cin >> Bonus >> AtkDa
            >> DefDa >> LvDa
            >> AtkGu >> DefGu
            >> LvGu;
        if (LvDa % 2 == 0)
            BonusDa = Bonus;
        if (LvGu % 2 == 0)
            BonusGu = Bonus;
        ValorGolpeDa = ValorGolpe(AtkDa, DefDa, BonusDa);
        ValorGolpeGu = ValorGolpe(AtkGu, DefGu, BonusGu);
        if (ValorGolpeDa == ValorGolpeGu)
            cout << "Empate" << '\n';
        else if (ValorGolpeDa < ValorGolpeGu)
            cout << "Guarte" << '\n';
        else if (ValorGolpeDa > ValorGolpeGu)
            cout << "Dabriel" << '\n';
    }
}

int ValorGolpe(int X, int Y, int Z)
{
	int Resultado;
	Resultado = (X + Y) / 2 + Z;
	return Resultado;
}