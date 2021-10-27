#include <iostream>
#include <iomanip>

using namespace std;

int main ()
{
	int NJogadores, SaqTot = 0, BloqTot = 0, AtkTot = 0,
		SaqSucTot = 0, BloqSucTot = 0, AtkSucTot = 0, i;
	char NomeJogador[24];
	float PontosSaq, PontosBloq, PontosAtk;
	cout << fixed << setprecision(2);
	cin >> NJogadores;
	int Saq[NJogadores],    Bloq[NJogadores],    Atk[NJogadores],
		SaqSuc[NJogadores], BloqSuc[NJogadores], AtkSuc[NJogadores];
	for(i = 0; i < NJogadores; i++)
    {
        cin >> NomeJogador;
        cin >> Saq[i]    >> Bloq[i]    >> Atk[i]
            >> SaqSuc[i] >> BloqSuc[i] >> AtkSuc[i];
    }
	for(i = 0; i < NJogadores; i++)
    {
        SaqTot     += Saq[i];
        BloqTot    += Bloq[i];
        AtkTot     += Atk[i];
        SaqSucTot  += SaqSuc[i];
        BloqSucTot += BloqSuc[i];
        AtkSucTot  += AtkSuc[i];
    }
	PontosSaq  = SaqSucTot  * 100.00 / SaqTot;
	PontosBloq = BloqSucTot * 100.00 / BloqTot;
	PontosAtk  = AtkSucTot  * 100.00 / AtkTot;
	cout << "Pontos de Saque: "    << PontosSaq  << " %." << '\n'
		 << "Pontos de Bloqueio: " << PontosBloq << " %." << '\n'
		 << "Pontos de Ataque: "   << PontosAtk  << " %." << '\n';
}