//URI-1767 usado como exemplo
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
#define inf 1000000000
#define inf64 1000000000000000000

typedef pair<int, int> ii;
typedef pair<char, int> ci;
typedef pair<string, int> si;
typedef vector< int > vi;
typedef vector< char > vc;
typedef vector<pair<int, int>> vii;
typedef vector<pair< int, pair<int, int>>> viii;
typedef vector<vector<int>> vvi;
typedef long long ll;

int Ans, N;
int Price[350], Peso[100];
int pd[150][100];
vi VetRec;

int Noel(int Ct, int W)
{
	if  (Ct >= N)
		return 0;
	if  (pd[Ct][W] != -1)
		return pd[Ct][W];
	if  (Peso[Ct] > W)
		return pd[Ct][W] = Noel(Ct + 1, W);

	int Op1 = Noel(Ct + 1, W);
	int Op2 = Price[Ct] + Noel(Ct + 1, W - Peso[Ct]);

	return pd[Ct][W] = max(Op1, Op2);
}

void Rec(int Ct, int W)
{
	if	(Ct >= N)
		return;
	if	(Peso[Ct] > W)
		return Rec(Ct +1, W);
	int Choice = Noel(Ct, W);
	int Op1 = Price[Ct] + Noel(Ct + 1, W - Peso[Ct]);
	int Op2 = Noel(Ct + 1, W);

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
	int Case;
	//freopen("imput.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d", &Case);
	while(Case--)
	{
		int PesoTot = 0, Brinks, Total = 0;
		Ans = 0;
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			scanf("%d %d", &Price[i], &Peso[i]);
			Total += Price[i];
		}
		
		memset(pd, -1, sizeof(pd));
		Brinks = Noel(0, 50);
		Rec(0, 50);

		printf("%d brinquedos\n", Brinks);
		for	(int i = 0; i < VetRec.size(); i++)
			PesoTot += Peso[VetRec[i]];
		printf("Peso: %d kg\n", PesoTot);
		printf("sobra(m) %d pacote(s)\n\n", N - VetRec.size());

		VetRec.clear();
	}

	return 0;
}