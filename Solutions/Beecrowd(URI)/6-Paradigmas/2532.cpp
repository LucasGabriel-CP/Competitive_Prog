#include <bits/stdc++.h>

using namespace std;

#define inf 123456789
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

int dp[1010][2050], peso[1010], valor[1010];
int N, P;

void solve() {
	for (int i = 0; i <= P; ++i) dp[0][i] = inf;
	for (int i = 1; i <= N; ++i) dp[i][0] = 0;

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= P; ++j) {
			if (peso[i - 1] >= j)
				dp[i][j] = min(dp[i - 1][j], valor[i - 1]);
			else
				dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - peso[i - 1]] + valor[i - 1]);
		}
	}
	printf("%d\n", dp[N][P] == inf ? -1 : dp[N][P]);
}

int main()
{
	while (scanf("%d %d", &N, &P) != EOF)
	{
		forn(i, N) {
			scanf("%d %d", &peso[i], &valor[i]);
		}
		solve();
	}

	return 0;
}