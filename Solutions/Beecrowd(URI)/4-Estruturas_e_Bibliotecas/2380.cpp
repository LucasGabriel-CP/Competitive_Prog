#include <bits/stdc++.h>

using namespace std;

#define sz 100050

struct aresta
{
	int a, b, p;
};
bool Comp(aresta a, aresta b) { return a.p < b.p; }

int pai[sz];
int Rank[sz];

int acha_pai(int X)
{
	if (pai[X] == X)
		return X;
	return pai[X] = acha_pai(pai[X]);
}

void unir(int X, int Y)
{
	X = acha_pai(X);
	Y = acha_pai(Y);
	if (Rank[X] > Rank[Y])
		pai[Y] = X;
	else
		if (Rank[X] < Rank[Y])
			pai[X] = Y;
		else
		{
			pai[Y] = X;
			Rank[X]++;
		}
}

int main()
{
	for (int i = 0; i < sz; i++) pai[i] = i;
	for (int i = 0; i < sz; i++) Rank[i] = 1;
	int N, M; scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		int O, D;
		char Op; scanf(" %c %d %d", &Op, &O, &D);
		if (Op == 'C')
		{
			if (acha_pai(O) == acha_pai(D))
				printf("S\n");
			else
				printf("N\n");
		}
		else
		{
			unir(O, D);
		}
	}
}