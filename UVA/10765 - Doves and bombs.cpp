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
#include <sstream>
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

int N, M, Timer, Ans;
vector<bool> Visit;
vi AdjList[10050], tin, low;
map<int, int> Bridge;
vii Cut;

bool comp(ii a, ii b)
{
	if (a.s == b.s)
		return a.f < b.f;
	return a.s > b.s;
}

void DFS(int v, int p = -1)
{
	Visit[v] = true;
	tin[v] = low[v] = Timer++;
	int children = 0;
	for (int to : AdjList[v])
	{
		if (to == p)	continue;
		if (Visit[to])
			low[v] = min(low[v], tin[to]);
		else
		{
			++children;
			DFS(to, v);
			low[v] = min(low[v], low[to]);
			if (low[to] >= tin[v])
				Bridge[v]++;
		}
	}
	if (p == -1 && children == 1)	Bridge[v] = 1;
}

void FindBridge()
{
	Ans = 0;
	Timer = 0;
	Visit.assign(N, false);
	tin.assign(N, -1);
	low.assign(N, -1);
	Cut.clear();

	int Conect = 0;
	for (int i = 0; i < N; i++)	
	{
		if (!Visit[i])
		{
			Conect++;
			DFS(i);
		}
	}
	Cut.push_back({ 0, Bridge[0] + Conect - 1 });
	for (int i = 1; i < N; i++)
	{
		if (Bridge.count(i))
			Cut.push_back({ i, Bridge[i] + Conect });
		else
			Cut.push_back({ i, Conect });
	}
	sort(Cut.begin(), Cut.end(), comp);
	for (int i = 0; i < M; i++)
		printf("%d %d\n", Cut[i].f, Cut[i].s);
}

int main()
{	
	while (scanf("%d %d", &N, &M), N && M)
	{
		int u, v;
		while (scanf("%d %d", &u, &v), u != -1 && v != -1)
		{
			AdjList[u].push_back(v);
			AdjList[v].push_back(u);
		}
		FindBridge();
		for (int i = 0; i < N; i++) AdjList[i].clear();
		Bridge.clear();
		printf("\n");
	}

	return 0;
}