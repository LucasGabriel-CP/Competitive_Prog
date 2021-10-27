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

	ll X; 
	vll Vet;
	while (scanf("%lld", &X) != EOF)
	{
		Vet.push_back(X);
		if (Vet.size() == 1)
			printf("%lld\n", X);
		else
			if (Vet.size() % 2 != 0)
			{
				nth_element(Vet.begin(), Vet.begin() + Vet.size() / 2, Vet.end());
				printf("%lld\n", Vet[Vet.size() / 2]);
			}
			else
			{
				int L = Vet.size() / 2 - 1;
				int R = L + 1;
				nth_element(Vet.begin(), Vet.begin() + L, Vet.end());
				ll F = Vet[L];
				nth_element(Vet.begin(), Vet.begin() + R, Vet.end());
				ll S = Vet[R];
				printf("%lld\n", (F + S) / 2);
			}
	}

	return 0;
}