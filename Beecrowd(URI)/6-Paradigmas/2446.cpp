#include <bits/stdc++.h>

using namespace std;

typedef vector< int > vi;

vi Moedas;

bool CoinChange(int S, int N)
{
	if (S == 0)
		return 1;
	if (N == 0 || S < 0)
		return 0;

	return CoinChange(S - Moedas[N - 1], N - 1) || CoinChange(S, N - 1);
}

int main()
{
	int N, K; scanf("%d %d", &N, &K);
	Moedas.assign(K, 0);

	for (int i = 0; i < K; i++)
	{
		scanf("%d", &Moedas[i]);
	}
	sort(Moedas.begin(), Moedas.end());
	printf("%c\n", CoinChange(N, K) ? 'S' : 'N');

	return 0;
}