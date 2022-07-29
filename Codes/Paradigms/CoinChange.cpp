//O(Val*M)
void CCDynamicP(vector<int> const &Moedas, int Val){
	int N = (int)Moedas.size();
	vector<int> table(Val + 1);
	table[0] = 0;
	for (int c = 1; c <= Val; ++c){
		auto& dp = table[c] = inf;
		for (int i = 0; i < N; ++i)
			if (c >= Moedas[i])
				dp = min(dp, table[c - Moedas[i]] + 1);
	}

	printf("%d\n", table[Val]);
}

//O(Val)
void CCGreedy(vector<int> const &Moedas, int Val){
	vector<int> Ans;
	sort(Moedas.begin(), Moedas.end());
	for (int i = 11; i >= 0; i--){
		while (Val >= Moedas[i]){
			Val -= Moedas[i];
			Ans.push_back(abs(i - 12));
		}
	}
	printf("%d\n", Ans.size());
	for (int i = 0; i < Ans.size() - 1; i++)
		printf("%d ", Ans[i]);
	printf("%d\n", Ans[Ans.size() - 1]);
}
