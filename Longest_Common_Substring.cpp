int LCS(string Str1, string Str2) //O(N * M) time, O(N * M) space
{
	int N = Str1.size();
	int M = Str2.size();
	int Ans = 0;
	vvi dp(N + 1, vi(M + 1));

	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= M; j++)
		{
			if (!i || !j)
				dp[i][j] = 0;
			else
				if (Str1[i - 1] == Str2[j - 1])
				{
					dp[i][j] = dp[i - 1][j - 1] + 1;
					Ans = max(Ans, dp[i][j]);
				}
				else
					dp[i][j] = 0;
		}
	}

	return Ans;
}

int LCSspaceOtm(string Str1, string Str2) //O(N * M) time, O(min(N, M)) space
{
	int N = Str1.size();
	int M = Str2.size();
	int Ans = 0;
	vvi dp(2, vi(M + 1));

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (Str1[i - 1] == Str2[j - 1])
			{
				dp[i % 2][j] = dp[(i - 1) % 2][j - 1] + 1;
				if (dp[i % 2][j] > Ans)
					Ans = dp[i % 2][j];
			}
			else
				dp[i % 2][j] = 0;
		}
	}

	return Ans;
}