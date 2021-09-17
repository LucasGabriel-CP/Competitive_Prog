int Vet[sz], P[sz];
int N;

void RecLIS(int end) //Reconstrução
{
	int x = end;
	stack<int> myS;
	for (; P[x] >= 0; x = P[x])
		myS.push(Vet[x]);
	printf("[%d", Vet[x]);
	for (; !myS.empty(); myS.pop())
		printf(", %d", myS.top());
	printf("]\n");
}

void LongestIncreasingSub()	//O(NlogN)
{
	vi L(N + 1);
	vi Lid(N + 1);

	int lis = 0;
	int lisEnd = 0;
	for (int i = 0; i < N; ++i)
	{
		int pos = lower_bound(L.begin(), L.begin() + lis, Vet[i]) - L.begin();
		L[pos] = Vet[i];
		Lid[pos] = i;
		P[i] = pos ? Lid[pos - 1] : -1;
		if (pos + 1 > lis)
		{
			lis = pos + 1;
			lisEnd = i;
		}
	}

	printf("Size of the LIS: %d\n", lis);
	RecLIS(lisEnd);
}