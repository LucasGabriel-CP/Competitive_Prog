#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

typedef long long ll;

int main()
{
	int N, K;
	while (scanf("%d %d", &N, &K) != EOF)
	{
		priority_queue<int> myPq;
		forn(i, N)
		{
			int Val; scanf("%d", &Val);
			myPq.push(Val);
		}
		ll Ans = 0;
		for (int i = 0; i < K; myPq.pop(), i++)
		{
			Ans = (Ans + myPq.top()) % mod;
		}
		printf("%lld\n", Ans % mod);
	}

	return 0;
}