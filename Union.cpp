//Union-FInd
//Achar representande de dois conjuntos

int pai[sz];
int Rank[sz];

priority_queue< ii, vector<ii>, greater<ii> > myPq;

int acha_pai(int X)
{
	if	(pai[X] == X)
		return X;
	return pai[X] = acha_pai(pai[X]);
}

void unir(int X, int Y)
{
	X = acha_pai(X);
	Y = acha_pai(Y);
	if	(Rank[X] > Rank[Y])
	{
		pai[Y] = X;
		Rank[X]++;
	}
	else
	{
		pai[X] = Y;
		Rank[Y]++;
	}
}

int main()
{
	int i;
	for	(int i = 0; i < 10; i++) pai[i]  = i;
	for	(int i = 0; i < 10; i++) Rank[i] = 1;
	int  N;	
	while(scanf("%d", &N) != EOF)
	{
		printf("%d\n", acha_pai(N));
		int M; scanf("%d %d", &N, &M);
		unir(N, M);
		for(int i = 0; i < 10; i++)
			printf("%d: %d %d\n", i, pai[i], Rank[i]);
	}
}
