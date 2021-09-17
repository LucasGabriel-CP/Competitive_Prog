//URI-1767 usado como exemplo

int Ans, N;
int Price[350], Peso[100];
int pd[150][100];
vi VetRec;

int Knap(int Ct, int W)
{
	if  (Ct >= N)
		return 0;
	if  (pd[Ct][W] != -1)
		return pd[Ct][W];
	if  (Peso[Ct] > W)
		return pd[Ct][W] = Knap(Ct + 1, W);

	int Op1 = Knap(Ct + 1, W);
	int Op2 = Price[Ct] + Knap(Ct + 1, W - Peso[Ct]);

	return pd[Ct][W] = max(Op1, Op2);
}

void Rec(int Ct, int W)
{
	if	(Ct >= N)
		return;
	if	(Peso[Ct] > W)
		return Rec(Ct +1, W);
	int Choice = Knap(Ct, W);
	int Op1 = Price[Ct] + Knap(Ct + 1, W - Peso[Ct]);
	int Op2 = Knap(Ct + 1, W);

	if	(Choice == Op1)
	{
		VetRec.push_back(Ct);
		return Rec(Ct + 1, W - Peso[Ct]);
	}
	else
		return Rec(Ct + 1, W);
}

int main()
{	
	memset(pd, -1, sizeof(pd));
	int Ans = Knap(0, 50);
	int PesoTot = 0;
	Rec(0, 50);

	printf("%d brinquedos\n", Ans);
	for	(int i = 0; i < VetRec.size(); i++)
		PesoTot += Peso[VetRec[i]];
	printf("Peso: %d kg\n", PesoTot);
	printf("sobra(m) %d pacote(s)\n\n", N - VetRec.size());
	VetRec.clear();

	return 0;
}