#include <bits/stdc++.h>

using namespace std;

#define MAX_N 10005
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

typedef vector< int > vi;
typedef long long ll;
int N;

ll dp[2][MAX_N];

ll solve(vi Vet)
{
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j + i < N; ++j) {
            if (i & 1) {
                dp[0][j] = max(dp[1][j + 1] + Vet[j], dp[1][j] + Vet[j + i]);
            }
            else {
                dp[1][j] = min(dp[0][j], dp[0][j + 1]);
            }
        }
    }

    return dp[0][0];
}

int main()
{
    while (scanf("%d", &N) != EOF)
    {
        vi Vet(N + 5);
        forn(i, N) {
            scanf("%d", &Vet[i]);
        }
        printf("%lld\n", solve(Vet));
    }

    return 0;
}