//Union-FInd
//Achar representande de dois conjuntos

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
