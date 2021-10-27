#include <bits/stdc++.h>

using namespace std;

#define mod 1000007

typedef long long ll;

int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        ll K, N; scanf("%lld %lld", &K, &N);
        queue< ll > myQ;
        if (N <= K)
            printf("%lld\n", (N - 1) % mod);
        else
        {
            ll Ans = (K - 1) * (K / 2.00);
            Ans %= mod;
            if (K == N + 1)
                printf("%lld\n", Ans);
            else
            {
                for (int i = 0; i < K; i++)
                    myQ.push(i % mod);
                myQ.push(Ans);
                for (int i = K; i < N - 1; i++)
                {
                    Ans += (Ans - myQ.front()) % mod;
                    myQ.push(Ans % mod);
                    myQ.pop();
                }
                printf("%lld\n", myQ.back());
            }
        }
    }
}