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
	int N = (int)Str1.size();
	int M = (int)Str2.size();
	vvi dp(2, vi(M + 1));
	bool bi;

	for (int i = 0; i <= N; i++)
	{
		bi = i & 1;
		for (int j = 0; j <= M; j++)
		{
			if (!i || !j)
				dp[bi][j] = 0;
			else
				if (Str1[i - 1] == Str2[j - 1])
					dp[bi][j] = dp[1 - bi][j - 1] + 1;
				else
					dp[bi][j] = max(dp[1 - bi][j], dp[bi][j - 1]);
		}
	}

	return dp[bi][M];
}