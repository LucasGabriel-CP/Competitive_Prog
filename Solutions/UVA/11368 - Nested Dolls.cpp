#include <bits/stdc++.h>

#ifdef PIZZA
__attribute__((destructor))static void __destroy__(){std::cerr<<"\nElapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";}
#define debug(x...) cerr<<"\x1b[91m"<<__LINE__<<" ["#x"] =",debug(x),cerr<<"\x1b[0m\n"
#define sleep(x) this_thread::sleep_for(chrono::milliseconds(x))
#define filIn freopen("input.txt", "r", stdin); //(__acrt_iob_func(0))
#define filOut freopen("output.txt", "w", stdout); //(__acrt_iob_func(1))
#else
#define assert(x) void(0)
#define filIn void(0)
#define filOut void(0)
#define sleep(x) void(0)
#endif

using namespace std;
const int maxn = 1e4+50, inf = 1e9;

int LIS(vector<pair<int, int>> const& vet, const int& n){
	multiset<int> L;
	int k = 0;
	for (int i = 0; i < n; ++i){
		auto pos = L.upper_bound(vet[i].first);
		if (pos == L.end()){
            ++k;
			L.insert(vet[i].first);
		}
		else{
            L.erase(pos);
            L.insert(vet[i].first);
		}
	}
	return k;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    filIn; filOut;
    int t, n; cin >> t;
    while(t--){
        cin >> n;
        vector<pair<int, int>> vet(n);
        for (pair<int, int> &i: vet) cin >> i.first >> i.second;
        sort(vet.begin(), vet.end(), [](const pair<int, int>& a, const pair<int, int>& b){
                                if (a.second != b.second)
                                    return a.second > b.second;
                                return a.first < b.first;
                            });
        cout << LIS(vet, n) << '\n';
    }
    return 0;
}
