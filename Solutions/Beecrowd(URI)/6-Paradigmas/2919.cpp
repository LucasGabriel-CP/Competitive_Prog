#include <bits/stdc++.h>

using namespace std;

#define inf 1000000000

long LIS(vector<long> Vet)
{
	vector<long> Temp;
	Temp.push_back(-inf);
	for (long i : Vet)
	{
		long Pos = lower_bound(Temp.begin(), Temp.end(), i) - Temp.begin();
		if (Pos == Temp.size())
			Temp.push_back(i);
		else
			Temp[Pos] = i;
	}
	return Temp.size() - 1;
}

int main()
{
	long N;
	while (scanf("%ld", &N) != EOF)
	{
		vector< long > Vet;
		for (long i = 0; i < N; i++)
		{
			long Val; scanf("%ld", &Val);
			Vet.push_back(Val);
		}
		printf("%ld\n", LIS(Vet));
	}
}