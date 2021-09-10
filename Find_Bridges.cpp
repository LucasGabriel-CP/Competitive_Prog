#include <assert.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

#define pi 3.141592653589793
#define eulerconstant 0.577215664901532
#define sz 550
#define f first
#define s second
#define inf ~(1<<31) - 1
#define inf64 1000000000000000000
#define goldenratio ((double)(1 + sqrt(5)) / 2)

typedef pair<int, int> ii;
typedef pair<char, int> ci;
typedef pair<string, int> si;
typedef pair<int, string> is;
typedef vector< int > vi;
typedef vector< long > vl;
typedef vector< char > vc;
typedef vector<pair<int, int>> vii;
typedef vector<pair< int, pair<int, int>>> viii;
typedef vector<vector<int>> vvi;
typedef long long ll;

int N, M, Timer;
vector<bool> Visit;
vi AdjList[1050], tin, low;
vii Bridge;

void DFS(int v, int p = -1)
{
	Visit[v] = true;
	tin[v] = low[v] = Timer++;	//Aumento o timer a cada vez que entro na DFS
	for (int to : AdjList[v])
	{
		if (Visit[to])
			low[v] = min(low[v], tin[to]); //Se visitado eu pego o mínimo do low do pai e do tin filho
		else
		{
			DFS(to, v);
			low[v] = min(low[v], low[to]);	//Pego o low que eu calculei na chamada passada e o atual
			if (low[to] > tin[v])
				Bridge.push_back({ v, to });	//Se o low do filho for maior que o tin do atual eu falo que é uma ponte
		}
	}
}

void FindBridge()
{
	Timer = 0;
	Visit.assign(N, false);
	tin.assign(N, -1);		//Time of entry Into Node
	low.assign(N, -1);		//Armazena o mínimo

	for (int i = 0; i < N; i++)
	{
		if (Visit[i])
			DFS(i);
	}
}

int main()
{


	return 0;
}