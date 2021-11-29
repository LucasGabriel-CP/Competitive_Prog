#include <bits/stdc++.h>

using namespace std;

#define MAX_N 105
#define inf ~(1<<31)
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

typedef vector< int > vi;

int N;
vi AdjList[MAX_N];
int dp[MAX_N][MAX_N * MAX_N / 2], R, K;

void solve()
{
    forn(i, R)
        dp[i][0] = 0;
    forn(i, K)
        dp[0][i] = 0;
    for (int i = 1; i <= R; ++i)
    {
        for (int j = 1; j <= K; ++j)
        {
            if ((int)AdjList[i - 1].size() > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - (int)AdjList[i - 1].size()] + (int)AdjList[i - 1].size());
        }
    }
    int Ans = 0;
    for (int i = 0; Ans != K && i < R; i++, Ans = dp[i][K]);
    printf("%c\n", Ans == K ? 'S' : 'N');
}

int main()
{
    while (scanf("%d %d", &R, &K) != EOF)
    {
        forn(i, R)
            AdjList[i].clear();
        forn(i, K)
        {
            int a, b; scanf("%d %d", &a, &b);
            --a; --b;
            AdjList[a].push_back(b);
            AdjList[b].push_back(a);
        }
        solve();
    }

    return 0;
}