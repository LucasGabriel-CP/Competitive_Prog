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

int main()
{
	int N; cin >> N;
	getchar();
	getchar();
	for (int i = 0; i < N; i++)
	{
		map<string, int> myMap;
		string Tree;
		int Count = 0;
		while (getline(cin, Tree))
		{
			if (Tree == "") break;
			myMap[Tree]++;
			Count++;
		}
		cout << fixed << setprecision(4);
		for (map<string, int>::iterator it = myMap.begin(); it != myMap.end(); ++it)
		{
			cout << it->f << ' ' << 1.00 * it->s / Count * 100 << '\n';
		}
		if (i + 1 < N)
			cout << '\n';
	}

	return 0;
}