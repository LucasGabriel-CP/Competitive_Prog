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

int matrix[8][8];

int di[8] = { 0, 1, 0,-1, -1, 1, 1, -1 };
int dj[8] = { 1, 0,-1, 0, 1, 1, -1, -1 };

bool checkQueen(int i, int j)
{
	for (int k = 0; k < 8; k++)
	{
		int ni = i + di[k];
		int nj = j + dj[k];

		while (ni >= 0 && ni < 8 && nj >= 0 && nj < 8) {
			if (matrix[ni][nj] == 1)
				return false;

			ni = ni + di[k];
			nj = nj + dj[k];
		}
	}

	return true;
}

int cnt = 0;

void backtracking(int row)
{
	if (row == 8) {
		// sucesso
		cnt++;
		return;
	}

	for (int i = 0; i < 8; i++) {
		matrix[row][i] = 1;

		if (checkQueen(row, i))
			backtracking(row + 1);
		
		matrix[row][i] = 0;
	}
}

int main()
{
	printf("alou\n");
	cnt = 0;
	backtracking(0);

	printf("%d\n", cnt);
}