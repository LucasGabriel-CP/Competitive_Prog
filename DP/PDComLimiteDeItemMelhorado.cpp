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
int value[60];
int weight[60];
string nomes[60];
int dp[60][51];

int f(int at, int w)
{
	if (at >= n)
		return 0;

	if (dp[at][w] != -1)
		return dp[at][w];

	if (w < weight[at])
		return dp[at][w] = f(at + 1, w);

	int p1 = value[at] + f(at + 1, w - weight[at]);
	int p2 = f(at + 1, w);

	return dp[at][w] = max(p1, p2);
}

vector<string> resp;
void rec(int at, int w)
{
	if (at >= n)
		return;

	if (w < weight[at])
		return rec(at + 1, w);

	int p1 = value[at] + f(at + 1, w - weight[at]);
	int p2 = f(at + 1, w);

	if (f(at, w) == p1)
	{
		resp.push_back(nomes[at]);
		return rec(at + 1, w - weight[at]);
	}
	else
		return rec(at + 1, w);
}

int main()
{
	freopen("Input.txt", "r", stdin);

	int c;
	scanf("%d", &n);
	scanf("%d", &c);

	int aux = 0;
	for (int i = 0; i < n; i++) {
		int v, p, qt;
		string nome;
		scanf("%d %d %d", &v, &p, &qt);
		cin >> nome;

		int pot = 1;

		while(qt > pot) {
			value[aux] = v * pot;
			weight[aux] = p * pot;
			nomes[aux] = nome;

			aux++;
			qt -= pot;
			pot *= 2;
		}

		value[aux] = v * qt;
		weight[aux] = p * qt;
		aux++;
	}

	n = aux;

	for (int i = 0; i < n; i++)
		for (int j = 0; j <= c; j++)
			dp[i][j] = -1;

	printf("%d\n", f(0, 50));
	rec(0, 50);

	for (int i = 0; i < resp.size(); i++)
		printf("%s\n", resp[i].c_str());
	printf("\n");
}