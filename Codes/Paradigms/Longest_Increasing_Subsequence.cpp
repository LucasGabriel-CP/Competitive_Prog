#include <bits/stdc++.h>

using namespace std;

int n;

vector<int> RecLIS(int end, vector<int> const& vet, vector<int> const& P){
	int x = end;
	vector<int> myS;
	for (; P[x] >= 0; x = P[x])
		myS.push_back(vet[x]);
    myS.push_back(vet[x]);
    reverse(myS.begin(), myS.end());
    return myS;
}

vector<int> LongestIncreasingSub(vector<int> const& vet){
	vector<int> L(n + 1), Lid(n + 1), P(n + 1);
	int lis = 0;
	int lisEnd = 0;
	for (int i = 0; i < n; ++i){
		int pos = lower_bound(L.begin(), L.begin() + lis, vet[i]) - L.begin();
		L[pos] = vet[i];
		Lid[pos] = i;
		P[i] = pos ? Lid[pos - 1] : -1;
		if (pos + 1 > lis){
			lis = pos + 1;
			lisEnd = i;
		}
	}
	cout << "lis: " << lis << '\n';
	return RecLIS(lisEnd, vet, P);
}
