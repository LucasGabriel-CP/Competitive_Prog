#include <bits/stdc++.h>

using namespace std;

int N;
double Pot[14];
int Muni[10050];
double pd[14][10050];

double RE4(int Ct, int W)
{

	if (Ct >= N)
		return 0;
	if (pd[Ct][W] != -1.0)
		return pd[Ct][W];
	if (Muni[Ct] > W)
		return pd[Ct][W] = RE4(Ct + 1, W);

	double Op1 = RE4(Ct + 1, W);
	double Op2 = Pot[Ct] + RE4(Ct + 1, W - Muni[Ct]);

	return pd[Ct][W] = max(Op1, Op2);
}

int main()
{
	map<string, double> Armas;
	Armas["HANDGUN"] = 2.0;
	Armas["RED9"] = 3.5;
	Armas["BLACKTAIL"] = 3.5;
	Armas["MATILDA"] = 2.0;
	Armas["HANDCANNON"] = 60.0;
	Armas["STRIKER"] = 12.0;
	Armas["TMP"] = 1.2;
	Armas["RIFLE"] = 12.0;
	map<string, int> Monstros;
	Monstros["GANADOS"] = 50;
	Monstros["COBRAS"] = 40;
	Monstros["ZEALOT"] = 75;
	Monstros["COLMILLOS"] = 60;
	Monstros["GARRADOR"] = 125;
	Monstros["LASPLAGAS"] = 100;
	Monstros["GATLINGMAN"] = 150;
	Monstros["REGENERATOR"] = 250;
	Monstros["ELGIGANTE"] = 500;
	Monstros["DR.SALVADOR"] = 350;
	while (scanf("%d", &N) != EOF)
	{
		unsigned long long ResMax = 0;
		double DanoTot = 0.0;
		string Str;

		for (int i = 0; i < N; i++)
		{
			cin >> Str;
			scanf("%d", &Muni[i]);
			Pot[i] = Armas[Str] * Muni[i];
		}

		int Zumbies;
		scanf("%d", &Zumbies);
		for (int i = 0; i < Zumbies; i++)
		{
			int Qt;
			cin >> Str;
			scanf("%d", &Qt);
			ResMax += (Qt * Monstros[Str]);
		}

		int Balas;
		scanf("%d", &Balas);
		for (int i = 0; i < N; i++)
			for (int j = 0; j <= Balas; j++)
				pd[i][j] = -1.0;

		double Brinks = RE4(0, Balas);
		DanoTot = pd[0][Balas];

		if (DanoTot < ResMax)
			printf("You Are Dead\n\n");
		else
			printf("Missao completada com sucesso\n\n");
	}

	return 0;
}