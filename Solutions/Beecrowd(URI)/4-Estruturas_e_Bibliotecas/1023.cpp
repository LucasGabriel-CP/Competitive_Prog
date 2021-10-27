#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<pair<int, int>> vii;
typedef long long ll;

int main()
{
	int N, Count = 1;
	scanf("%d", &N);
	while (N)
	{
		if (Count > 1)
			printf("\n");
		vector< ll > Vet(210, 0);
		priority_queue<ii, vii, greater<ii> > myPq;
		ll Totp = 0, TotA = 0;
		int Maior = 0;
		while (N--)
		{
			int X, Y; scanf("%d %d", &X, &Y);
			Vet[Y / X] += X;
			Maior = Maior < Y / X ? Y / X : Maior;
			TotA += Y;	Totp += X;
		}
		printf("Cidade# %d:\n", Count++);
		for (int i = 0; i < Maior; i++)
		{
			if (Vet[i])
				printf("%lld-%d ", Vet[i], i);
		}
		printf("%lld-%d\n", Vet[Maior], Maior);

		double Ans = floor(100 * (float)TotA / Totp) / 100;

		printf("Consumo medio: %.2lf m3.\n", Ans);
		scanf("%d", &N);
	}
}