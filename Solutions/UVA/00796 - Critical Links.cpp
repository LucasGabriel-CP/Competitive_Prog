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
	tin[v] = low[v] = Timer++;
	for (int to : AdjList[v])
	{
		if (to == p) continue;
		if (Visit[to])
			low[v] = min(low[v], tin[to]);
		else
		{
			DFS(to, v);
			low[v] = min(low[v], low[to]);
			if (low[to] > tin[v])
				Bridge.push_back({ min(v, to), max(to, v) });
		}
	}
}

void FindBridge()
{
	Timer = 0;
	Visit.assign(N, false);
	tin.assign(N, -1);
	low.assign(N, -1);

	for (int i = 0; i < N; i++)
	{
		if (!Visit[i])
			DFS(i);
	}
	printf("%d critical links\n", Bridge.size());
	sort(Bridge.begin(), Bridge.end());
	for (ii v : Bridge)
	{
		printf("%d - %d\n", v.f, v.s);
	}
	printf("\n");
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	while (scanf("%d", &N) != EOF)
	{
		for (int i = 0; i < N; i++)
		{
			int a, b;
			scanf("%d (%d)", &a, &M);
			while (M--)
			{
				scanf("%d", &b);
				AdjList[a].push_back(b);
			}
		}
		FindBridge();
		for (int i = 0; i < N; i++) AdjList[i].clear();
		Bridge.clear();
	}

	return 0;
}