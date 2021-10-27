#include <bits/stdc++.h>

using namespace std;

#define sz 4050

typedef pair<int, int> ii;
typedef vector< int > vi;

struct aresta
{
	int a, b, p;
};
bool Comp(aresta a, aresta b) { return a.p < b.p; }
bool CompMax(aresta a, aresta b) { return a.p > b.p; }

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

	int N; scanf("%d", &N);

	for (int i = 0; i < sz; i++) pai[i] = i;
	for (int i = 0; i < sz; i++) Rank[i] = 1;

	aresta Cabo;
	int U, V, W;
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d %d", &U, &V, &W);
		Cabo.a = U - 1;
		Cabo.b = V - 1;
		Cabo.p = W;
		Lis.push_back(Cabo);
	}
	sort(Lis.begin(), Lis.end(), CompMax);

	vector< aresta > Ans;
	int S = 0;
	for (int i = 0; i < Lis.size(); i++)
	{
		int X = Lis[i].a;
		int Y = Lis[i].b;
		int Z = Lis[i].p;
		if (acha_pai(X) != acha_pai(Y))
		{
			S += Z;
			unir(X, Y);
		}
	}
	printf("%d\n", S);

	for (int i = 0; i < sz; i++) pai[i] = i;
	for (int i = 0; i < sz; i++) Rank[i] = 1;
	S = 0;
	sort(Lis.begin(), Lis.end(), Comp);
	for (int i = 0; i < Lis.size(); i++)
	{
		int X = Lis[i].a;
		int Y = Lis[i].b;
		int Z = Lis[i].p;
		if (acha_pai(X) != acha_pai(Y))
		{
			S += Z;
			unir(X, Y);
		}
	}
	printf("%d\n", S);
}