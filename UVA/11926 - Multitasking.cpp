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
typedef vector< long long > vll;
typedef vector< char > vc;
typedef vector<pair<int, int>> vii;
typedef vector<pair< int, pair<int, int>>> viii;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvf;
typedef long long ll;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int N, M;
	while (scanf("%d %d", &N, &M), N || M)
	{
		bitset<1000050> foo;
		bool ok = true;
		for (int i = 0; i < N; i++)
		{
			int O, D; scanf("%d %d", &O, &D);
			for (int j = O; j < D && ok; j++)
			{
				if (foo[j])
					ok = false;
				foo.set(j);
			}
		}
		for (int i = 0; i < M; i++)
		{
			int O, D, Rep; scanf("%d %d %d", &O, &D, &Rep);
			while (D <= 1000000)
			{
				for (int j = O; j < D && ok; j++)
				{
					if (foo[j])
						ok = false;
					foo.set(j);
				}
				O += Rep;
				D += Rep;
			}
			if (D > 1000000)
				for (int j = O; j < 1000000 && ok; j++)
				{
					if (foo[j])
						ok = false;
					foo.set(j);
				}
		}
		printf("%sCONFLICT\n", ok ? "NO " : "");
	}

	return 0;
}