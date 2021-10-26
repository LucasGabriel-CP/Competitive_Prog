#include <bits/stdc++.h>

using namespace std;

typedef vector< int > vi;
typedef long long ll;

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		int N, C, M; scanf("%d %d %d", &N, &C, &M);
		int Maior = -1;
		vi Andares(N + 1, 0);
		priority_queue<int> myPq;
		for (int i = 0; i < M; i++)
		{
			int Val; scanf("%d", &Val);
			myPq.push(Val);
			Maior = max(Maior, Val);
		}

		ll Soma = 0;
		int AndMa = -1;
		while (M && (int)myPq.size())
		{
			for (int j = 0; j < C && (int)myPq.size(); j++)
			{
				if (!j) AndMa = myPq.top();
				myPq.pop();
			}
			Soma += ((ll)AndMa * 2);
			M -= C;
		}

		printf("%lld\n", Soma);
	}

	return 0;
}