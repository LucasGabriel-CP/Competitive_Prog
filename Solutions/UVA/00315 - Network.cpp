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
vi AdjList[1050], tin, low;
map<int, int> Bridge;

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
			DFS(to, v);
			low[v] = min(low[v], low[to]);
			if (low[to] >= tin[v] && p != -1)
				Bridge[v]++;
			++children;
		}
	}
	if (p == -1 && children > 1)	Bridge[v]++;
}

void FindBridge()
{
	Ans = 0;
	Timer = 0;
	Visit.assign(N, false);
	tin.assign(N, -1);
	low.assign(N, -1);

	for (int i = 0; i < N; i++)
	{
		if (!Visit[i])
		{
			DFS(i);
		}
	}

	cout << Bridge.size() << '\n';
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(0);
	while (cin >> N, N)
	{
		cin.ignore();
		string s;
		while (getline(cin, s), s != "0")
		{
			stringstream ss(s);
			int u, v;
			ss >> u;
			while (ss >> v)
			{
				AdjList[u-1].push_back(v-1);
				AdjList[v-1].push_back(u-1);
			}
		}
		FindBridge();
		for (int i = 0; i < N; i++) AdjList[i].clear();
		Bridge.clear();
	}

	return 0;
}