#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <bitset>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <stack>
#include <list>
#include <limits.h>
#include <list>
#include <fstream>
#include <string.h>

using namespace std;

#define pi 3.141592653589793
#define sieveBOUND 100000
#define inf32 1000000000
#define inf64 1000000000000000000
#define BOUNDS 1000000
#define ll long long int
#define ii pair<int, int>
#define db double
#define MOD 1000000007
#define vi vector<int>
#define limit 500010

#define tos to_string

#define sum(a, b) (ll)((((ll)(a % MOD) + (ll)(b % MOD)) + MOD) % MOD)
#define mult(a, b) (((ll)(a % MOD) * (ll)(b % MOD)) % MOD)
#define goldenratio ((double)(1 + sqrt(5)) / 2) 
#define binet(a) (ll)round((((double)pow(goldenratio, a) - (double)pow(-goldenratio, -a)) / sqrt(5)))
#define eulerconstant 0.577215664901532
#define isvalid(a_, b_, n_, m_) (a_ >= 0 && a_ < n_ && b_ >= 0 && b_ < m_)

int n;
int value[100];
int weight[100];
int pd[100][151];


// 2^n
// n * c
// 10000 * 100
// 1000000

int f(int at, int w)
{
	if (at == n)
		return 0;

	if (pd[at][w] != -1)
		return pd[at][w];

	if (weight[at] > w)
		return f(at + 1, w);

	int p1 = f(at + 1, w);
	int p2 = value[at] + f(at + 1, w - weight[at]);
	int resp = max(p1, p2);

	pd[at][w] = resp;

	return resp;
}

int main()
{
	// peso maximo da mochila vai ser 150
	int c; scanf("%d", &c);

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d %d", &value[i], &weight[i]);

	//limpa a PD
	
	memset(pd, -1, sizeof(pd));

	// for (int i = 0; i < n; i++)
		// for (int j = 0; j <= c; j++)
			// pd[i][j] = -1;

	printf("%d\n", f(0, c));
}