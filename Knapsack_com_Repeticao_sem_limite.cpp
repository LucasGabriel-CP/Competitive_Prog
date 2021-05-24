//Knapsack com repetição e sem limite
//URI-2299 como exemplo
#include <iostream>
#include <cstring>
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

#define pi 3.141592653589793
#define eulerconstant 0.577215664901532
#define sz 4050
#define f first
#define s second
#define inf 1000000

using namespace std;

typedef pair<int, int> ii;
typedef pair<char, int> ci;
typedef pair<string, int> si;
typedef vector< int > vi;
typedef vector< char > vc;
typedef vector<pair<int, int>> vii;
typedef vector<pair< int, pair<int, int>>> viii;
typedef vector<vector<int>> vvi;

int N;
int Points[110], Tempo[110];
int pd[110][650];

int Brinks(int Ct, int W)
{
	if  (Ct == N)
		return 0;
	if  (pd[Ct][W] != -1)
		return pd[Ct][W];
	if  (Tempo[Ct] > W)
		return pd[Ct][W] = Brinks(Ct + 1, W);

	int Op1 = Brinks(Ct + 1, W);
	int Op2 = Points[Ct] + Brinks(Ct, W - Tempo[Ct]);

	int Ans = max(Op1, Op2);
 
	pd[Ct][W] = Ans;

	return Ans;
}

int main()
{	
	int Case = 1;
	//freopen("imput.txt","r",stdin);
	while(scanf("%d", &N) && N)
	{
		int P;	scanf("%d", &P);

		for (int i = 0; i < N; i++)
			scanf("%d%d", &Tempo[i], &Points[i]);

		memset(pd, -1, sizeof(pd));

		printf("Instancia %d\n", Case);
		Case++;
		printf("%d\n\n", Brinks(0, P));
	}

	return 0;
}