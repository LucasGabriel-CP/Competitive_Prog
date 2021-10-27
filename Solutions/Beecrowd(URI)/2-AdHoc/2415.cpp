#include <iostream>

using namespace std;

int main()
{
	int Valores, Seq = 1, SeqMaior = 0;
	cin >> Valores;
	int Valor[Valores - 1];
	for (int i = 0; i < Valores; i++)
    {
        cin >> Valor[i];
    }
	for (int i = 1; i < Valores; i++)
    {
        if (Valor[i] == Valor [i - 1])
        Seq++;
        if (Seq > SeqMaior)
        SeqMaior = Seq;
        if (Valor[i] != Valor [i - 1])
        Seq = 1;
    }
	cout << SeqMaior << '\n';
}