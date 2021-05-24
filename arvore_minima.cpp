#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <stack>
#include <list>
#include <limits.h>
#include <string.h>
#include <iomanip>

using namespace std;

#define pi 3.141592653589793
#define eulerconstant 0.577215664901532
#define sz 4050
#define f first
#define s second
#define inf 1000000

typedef pair<int, int> ii;
typedef pair<char, int> ci;
typedef pair<string, int> si;
typedef vector< int > vi;
typedef vector< char > vc;
typedef vector<pair<int, int>> vii;
typedef vector<pair< int, pair<int, int>>> viii;
typedef vector<vector<int>> vvi;
typedef long long ll;

struct aresta
{
	int a, b, p;
};
bool Comp(aresta a, aresta b)	{ return a.p < b.p; }

int pai[sz];
int Rank[sz];
vector< aresta > Lis;
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
	for	(int i = 0; i < 10; i++) pai[i]  = i;
	for	(int i = 0; i < 10; i++) Rank[i] = 1;
	aresta Hm;
	for	(int i = 0; i < 10; i++)
	{
		scanf("%d %d %d", &Hm.a, &Hm.b, &Hm.p);  //Adiciona a aresta a->b com peso p
		Lis.push_back(Hm);
	}
	sort(Lis.begin(), Lis.end(), Comp);
	
	vector< aresta > Ans;
	int S = 0;
	for	(int i = 0; i < 10; i++)
	{
		int X = Lis[i].a;
		int Y = Lis[i].b;
		int P = Lis[i].p;
		if	(acha_pai(X) != acha_pai(Y))
		{
			Ans.push_back(Lis[i]);
			S += P;
			unir(X,Y);
		}
	}
	printf("Ans: %d\n", S);
	for	(int i = 0; i < Ans.size(); i++)
		printf("Aresta: %d - %d | Peso: %d\n", Ans[i].a, Ans[i].b, Ans[i].p);
}
