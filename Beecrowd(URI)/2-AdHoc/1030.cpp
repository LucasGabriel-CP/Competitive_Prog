#include <cstdio>

using namespace std;

int Flav(int At, int N, int K, int Vet[])
{
	if (N == 1)
		return Vet[At];

	for (int i = At; i < N - 1; i++)
		Vet[i] = Vet[i + 1];

	return Flav((At + K) % (N - 1), N - 1, K, Vet);
}

int main()
{
	int Case, N, Vet[10010],
		K, Result;
	scanf("%d", &Case);

	for (int i = 0; i < Case; i++)
	{
		for (int j = 0; j < 10010; j++)
			Vet[j] = j + 1;

		scanf("%d %d", &N, &K);
		Result = Flav((K - 1) % N, N, K - 1, Vet);
		printf("Case %d: %d\n", i + 1, Result);
	}

	return 0;
}