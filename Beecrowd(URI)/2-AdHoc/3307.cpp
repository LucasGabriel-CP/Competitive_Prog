#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

int main()
{
	int N;	scanf("%d", &N);

	forn(i, N)
	{
		int A; scanf("%d", &A);
		double Ans = sqrt(A / (4 * 3.14));
		if (Ans < 12.0000)
		{
			printf("vermelho = R$ %.2lf\n", A * 0.09);
		}
		else
			if (Ans <= 15.0000)
				printf("azul = R$ %.2lf\n", A * 0.07);
			else
				printf("amarelo = R$ %.2lf\n", A * 0.05);
	}

	return 0;
}