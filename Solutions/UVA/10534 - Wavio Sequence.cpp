#include <bits/stdc++.h>

#ifdef PIZZA
__attribute__((destructor))static void __destroy__(){std::cerr<<"\nElapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";}
#endif

using namespace std;

const int maxn = 1e4+50, inf = 1e9;

int start;

vector<int> RecLIS(int end, vector<int> const& vet, vector<int> const& P){
	int x = end;
	vector<int> myS;
	for (; P[x] != -1; x = P[x])
		myS.push_back(vet[x]);
    myS.push_back(vet[x]);
    start = x;
    reverse(myS.begin(), myS.end());
    return myS;
}

vector<int> LongestIncreasingSub(vector<int> const& vet, vector<int>& save, int n){
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
        save[i] = lis;
	}
	return RecLIS(lisEnd, vet, P);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    while(cin >> n){
        vector<int> vet(n), save1(n), save2(n);
        for (int &i: vet) cin >> i;
        vector<int> lis1 = LongestIncreasingSub(vet, save1, n);
        vector<int> vet2(vet.begin() + start, vet.end());
        reverse(vet2.begin(), vet2.end());
        vector<int> lis2 = LongestIncreasingSub(vet2, save2, (int)vet2.size());
        for (int i = (int)vet2.size(); i < n; ++i) save2[i] = save2[(int)vet2.size()-1];
        reverse(save2.begin(), save2.end());
        int x, y, ans = -1;
        for (int i = 0; i < n; ++i){
            ans = max(ans, 2*min(save1[i], save2[i])-1);
        }
        cout << ans << '\n';
    }

    return 0;
}
