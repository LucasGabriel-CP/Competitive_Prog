#include <iostream>

using namespace std;

int main ()
{
	int Hi, Hf, Mi, Mf;
	cin >> Hi >> Mi >>Hf >> Mf;
	if (Hi == Hf && Mi == Mf) 
        cout << "O JOGO DUROU 24 HORA(S) E 0 MINUTO(S)" << "\n";
	else if (Hi == Hf && Mi > Mf) 
        cout << "O JOGO DUROU 23 HORA(S) E " << 60 - (Mi - Mf) << " MINUTO(S)" << "\n"; 
	else if (Hi == Hf && Mi < Mf) 
        cout << "O JOGO DUROU 0 HORA(S) E " << Mf - Mi << " MINUTO(S)" << "\n";
	else if (Hi == 0 && Hf <= 23 && Mi == 0 && Mf > 0) 
        cout << "O JOGO DUROU " << Hf << " HORA(S) E " << Mf << " MINUTO(S)"<< "\n";
	else if (Hi == 0 && Hf <= 23 && Mi == Mf) 
        cout << "O JOGO DUROU " << Hf << " HORA(S) E 0 MINUTO(S)" << "\n";
	else if (Hi == 0 && Hf <= 23 && Mi > Mf) 
        cout << "O JOGO DUROU " << Hf - 1 << " HORA(S) E " << 60 - (Mi - Mf) << " MINUTO(S)" << "\n";
	else if (Hi == 0 && Hf <= 23 && Mi < Mf) 
        cout << "O JOGO DUROU " << Hf << " HORA(S) E " << Mf - Mi << " MINUTO(S)" << "\n";
	else if (Hi != 0 && Hf == 0 && Mi == Mf) 
        cout << "O JOGO DUROU " << 24 - Hi << " HORA(S) E 0 MINUTO(S)" << "\n";
	else if (Hi != 0 && Hf == 0 && Mi > Mf) 
        cout << "O JOGO DUROU " << (24 - Hi) - 1 << " HORA(S) E " << 60 - (Mi - Mf) << " MINUTO(S)" << "\n";
	else if (Hi != 0 && Hf == 0 && Mi == 0 && Mf > 0) 
        cout << "O JOGO DUROU " << 24 - Hi << " HORA(S) E " << Mf << " MINUTO(S)" << "\n";
	else if (Hi != 0 && Hf == 0 && Mi < Mf) 
        cout << "O JOGO DUROU " << 24 - Hi << " HORA(S) E " << Mf - Mi << " MINUTO(S)" << "\n";
	else if (Hi > Hf && Mi == Mf) 
        cout << "O JOGO DUROU " << 24 - Hi + Hf << " HORA(S) E 0 MINUTO(S)" << "\n";
	else if (Hi > Hf && Mi == 0 && Mf > 0) 
        cout << "O JOGO DUROU " << 24 - Hi + Hf << " HORA(S) E " << Mf << " MINUTO(S)" << "\n";
	else if (Hi > Hf && Mi > Mf) 
        cout << "O JOGO DUROU " << (24 - Hi + Hf) - 1 << " HORA(S) E " << 60 - (Mi - Mf) << " MINUTO(S)" << "\n";
	else if (Hi > Hf && Mi < Mf) 
        cout << "O JOGO DUROU " << 24 - Hi + Hf << " HORA(S) E " << Mf - Mi << " MINUTO(S)" << "\n";
	else if (Hi < Hf && Mi == Mf) 
        cout << "O JOGO DUROU " << Hf - Hi << " HORA(S) E 0 MINUTO(S)" << "\n";
	else if (Hi < Hf && Mi == 0 && Mf > 0) 
        cout << "O JOGO DUROU " << Hf - Hi << " HORA(S) E " << Mf << " MINUTO(S)" << "\n";
	else if (Hi < Hf && Mi > Mf) 
        cout << "O JOGO DUROU " << (Hf - Hi) - 1 << " HORA(S) E " << 60 - (Mi - Mf) << " MINUTO(S)" << "\n";
	else if (Hi < Hf && Mi < Mf) 
        cout << "O JOGO DUROU " << Hf - Hi << " HORA(S) E " << Mf - Mi << " MINUTO(S)" << "\n";
}