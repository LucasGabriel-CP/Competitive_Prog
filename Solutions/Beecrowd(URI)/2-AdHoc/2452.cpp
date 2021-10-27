#include <iostream>
#include <cstdio>

using namespace std;

int main() 
{
	int F; scanf("%d", &F);
	int Left[F], Right[F], Vet[F];
	bool Visit[F];
	for	(int i = 0; i < F; i++) Visit[i] = 0;

	int R; scanf("%d", &R);
	for (int i = 0; i < R; i++)
	{
		scanf("%d", &Vet[i]);
		Vet[i]--;

		Right[i] = Vet[i] + 1;
		Left[i] = Vet[i] - 1;

		Visit[Vet[i]] = true;
	}
	
	int Count = R, Dia = 0;
	while (Count < F)
	{
		for (int i = 0; i < R; i++)
		{
			if	(Right[i] < F)
			{
				if	(!Visit[Right[i]])
				{
					Visit[Right[i]] = true;
					Count++;
					Right[i]++;
				}
			}
			if	(Left[i] >= 0)
			{
				if	(!Visit[Left[i]])
				{
					Visit[Left[i]] = true;
					Count++;
					Left[i]--;
				}
			}

		}
		Dia++;
	}
	
	printf("%d\n", Dia);

}