#include <bits/stdc++.h>

using namespace std;

#define sz 550

typedef pair<int, int> ii;

struct aresta
{
	int a, b, p;
};
bool Comp(aresta a, aresta b) { return a.p < b.p; }

int pai[sz];
int Rank[sz];
vector< aresta > Lis;

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
	for (int i = 0; i < sz; i++) pai[i] = i;
	for (int i = 0; i < sz; i++) Rank[i] = 1;
	aresta Hm;
	int N, M; scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d %d", &Hm.a, &Hm.b, &Hm.p);
		Lis.push_back(Hm);
		Lis.push_back({ Hm.b, Hm.a, Hm.p });
	}
	sort(Lis.begin(), Lis.end(), Comp);

	int S = 0;
	for (int i = 0; i < M * 2; i++)
	{
		int X = Lis[i].a;
		int Y = Lis[i].b;
		int P = Lis[i].p;
		if (acha_pai(X) != acha_pai(Y))
		{
			S += P;
			unir(X, Y);
		}
	}
	printf("%d\n", S);
}