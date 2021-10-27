#include <iostream>

using namespace std;

int main()
{
	int QntIn, NAcoes, QntTotD,
		QntTotE, QntTotF, Qnt;
	char Acao, Nome,
		 Nome1, Nome2;
	cin >> QntIn >> NAcoes;
	QntTotD = QntIn;
	QntTotE = QntIn;
	QntTotF = QntIn;
	for(int i = 0; i < NAcoes; i++)
    {
        cin >> Acao;
        if (Acao == 'C')
        {
            cin >> Nome >> Qnt;
            if (Nome == 'D') 
                QntTotD = QntTotD - Qnt;
            if (Nome == 'E')
                QntTotE -= Qnt;
            if(Nome == 'F')
                QntTotF -= Qnt;
        }
        else if (Acao == 'V')
        {
            cin >> Nome >> Qnt;
            if (Nome == 'D') 
                QntTotD += Qnt;
            else if(Nome == 'E')
                QntTotE += Qnt;
            else if(Nome == 'F')
                QntTotF += Qnt;
        }
        else if (Acao == 'A')
        {
            cin >> Nome1 >> Nome2 >> Qnt;
            if (Nome1 == 'D')
                QntTotD = QntTotD + Qnt;
            else if (Nome1 == 'E')
                QntTotE += Qnt;
            else if (Nome1 == 'F')
                QntTotF += Qnt;
            if (Nome2 == 'D') 
                QntTotD -= Qnt;
            else if(Nome2 == 'E')
                QntTotE -= Qnt;
            else if(Nome2 == 'F')
                QntTotF = QntTotF - Qnt;
        }
    }
	cout << QntTotD << " " << QntTotE << " " << QntTotF << '\n';
}