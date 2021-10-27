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
#include <assert.h>
#include <bitset>

using namespace std;

#define pi 3.141592653589793
#define eulerconstant 0.577215664901532
#define sz 10050
#define f first
#define s second
#define inf ~(1<<31) - 1
#define inf64 1000000000000000000

typedef pair<int, int> ii;
typedef pair< int, pair<int, int>> iii;
typedef pair<char, int> ci;
typedef pair<string, int> si;
typedef vector< int > vi;
typedef vector< char > vc;
typedef vector<pair<int, int>> vii;
typedef vector<pair< int, pair<int, int>>> viii;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvf;
typedef long long ll;

int main()
{
	int N;
	while (scanf("%d", &N) != EOF)
	{
		int Ant;  scanf("%d", &Ant);
		priority_queue< int > myQ;
		bool ok = true;
		for (int i = 1; i < N; i++)
		{
			int cur; scanf("%d", &cur);
			myQ.push(abs(Ant - cur));
			Ant = cur;
		}

		while (ok && !myQ.empty())
		{
			if (myQ.top() != --N)
				ok = false;
			myQ.pop();
		}
		printf("%s\n", ok ? "Jolly" : "Not jolly");
	}

	return 0;
}