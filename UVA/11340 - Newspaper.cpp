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
	//freopen("input.txt", "r", stdin);
	int N; scanf("%d", &N);
	while (N--)
	{
		map< unsigned char, int > myMap;
		int K, val; scanf("%d", &K);
		unsigned char Car;
		while (K--)
		{
			scanf(" %c %d", &Car, &val);
			myMap[Car] = val;
		}
		int T;
		scanf("%d", &T);
		cin.get();
		int Ans = 0;
		while (T)
		{
			Car = (unsigned char)cin.get();
			if (Car == '\n' || Car == 255)
				T--;
			else
			{
				if (myMap.count(Car))
					Ans += myMap[Car];
			}
		}

		printf("%.2f$\n", Ans/100.00);
	}

	return 0;
}