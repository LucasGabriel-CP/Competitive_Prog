//Preciso descobrir como fazer a reconstrução ainda XD
int LIS(vi& Numbers)
{
	int N = Numbers.size();
	vi DP(N + 1, inf);
	DP[0] = -inf;

	for (int i = 0; i < N; ++i)
	{
		int j = upper_bound(DP.begin(), DP.end(), Numbers[i]) - DP.begin();
		if (DP[j - 1] < Numbers[i] && Numbers[i] < DP[j])
			DP[j] = Numbers[i];
	}

	int Ans = 0;
	for (int i = 0; i <= N; ++i)
	{
		if (DP[i] < inf)
			Ans = i;
	}

	return Ans;
}