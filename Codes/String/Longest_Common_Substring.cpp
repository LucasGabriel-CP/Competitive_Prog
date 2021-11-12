typedef vector<vector<int>> vvi;

void Reconstruc(vvi& dp, string& Str1, string& Str2, int N, int M)
{
	int ultimo = 0;
	int i = N, j = M, idx = dp[N][M];
	string Ans;
	Ans.assign("", idx + 1);
	while (i > 0 && j > 0)
	{
		if (Str1[i - 1] == Str2[j - 1])
		{
			Ans[idx] = Str1[i - 1];
			--i; --j; --idx;
		}
		else
			if (dp[i - 1][j] > dp[i][j - 1])
				--i;
			else
				--j;
	}
	cout << Ans << '\n';
}

int LCS(string& Str1, string& Str2)
{
	int N = (int)Str1.size();
	int M = (int)Str2.size();
	vvi dp(N + 1, vi(M + 1));

	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= M; j++)
		{
			if (!i || !j)
				dp[i][j] = 0;
			else
				if (Str1[i - 1] == Str2[j - 1])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	Reconstruc(dp, Str1, Str2, N, M);
	return dp[N][M];
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