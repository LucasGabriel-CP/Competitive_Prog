#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

typedef vector< int > vi;
typedef vector<vector<int>> vvi;

int main()
{
	long double TerA = 0.0;
	vvi Vetxy(4, vi(2));
	forn(i, 4)
	{
		scanf("%d %d", &Vetxy[i][0], &Vetxy[i][1]);
	}
	TerA = (1 / 2) * (Vetxy[0][0] - Vetxy[2][0]) * (Vetxy[1][1] - Vetxy[3][1])
		- (Vetxy[1][0] - Vetxy[3][0]) * (Vetxy[0][1] - Vetxy[2][1]);
	long double TerB = 0.0;
	forn(i, 4)
	{
		scanf("%d %d", &Vetxy[i][0], &Vetxy[i][1]);
	}
	TerB = (1 / 2) * (Vetxy[0][0] - Vetxy[2][0]) * (Vetxy[1][1] - Vetxy[3][1])
		- (Vetxy[1][0] - Vetxy[3][0]) * (Vetxy[0][1] - Vetxy[2][1]);
	printf("terreno %c\n", abs(TerA) > abs(TerB) ? 'A' : 'B');

	return 0;
}