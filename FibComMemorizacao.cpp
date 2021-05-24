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

unsigned ll pd[10000];

unsigned ll f(int at)
{
	if (at == 0 || at == 1)
		return 1;

	if (pd[at] != -1)
		return pd[at];

	return pd[at] = f(at - 1) + f(at - 2);
}

int main()
{
	unsigned ll n;

	memset(pd, -1, sizeof(pd));

	while (cin >> n && n != -1) {
		cout << f(n) << '\n';
	}
}
