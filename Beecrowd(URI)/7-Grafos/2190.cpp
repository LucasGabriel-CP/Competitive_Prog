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
priority_queue< ii, vector<ii>, greater<ii> > myPq;

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
	aresta Hm;
	int N, M, Count = 1;
	while (scanf("%d %d", &N, &M), N)
	{
		for (int i = 0; i < sz; i++) pai[i] = i;
		for (int i = 0; i < sz; i++) Rank[i] = 1;
		for (int i = 0; i < M; i++)
		{
			scanf("%d %d %d", &Hm.a, &Hm.b, &Hm.p);
			Lis.push_back(Hm);
		}
		sort(Lis.begin(), Lis.end(), Comp);

		vector< aresta > Ans;
		for (int i = 0; i < M; i++)
		{
			int X = Lis[i].a;
			int Y = Lis[i].b;
			int P = Lis[i].p;
			if (acha_pai(X) != acha_pai(Y))
			{
				Ans.push_back(Lis[i]);
				unir(X, Y);
			}
		}
		printf("Teste %d\n", Count++);
		for (int i = 0; i < Ans.size(); i++)
			printf("%d %d\n", min(Ans[i].a, Ans[i].b), max(Ans[i].b, Ans[i].a));
		printf("\n");
		Lis.clear();
	}
}