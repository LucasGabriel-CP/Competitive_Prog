#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    int n;
    while(t--){
        cin >> n;
        set<pair<int, int>> mySet;
        vector<pair<int, int>> vet;
        for (int i = 0; i < n; ++i){
            int x, y; cin >> x >> y;
            if (!mySet.count({x, y})){
                vet.push_back({x, y});
                mySet.insert({x, y});
            }
        }
        sort(vet.begin(), vet.end());
        n = (int)vet.size();
        double midx = (vet[0].first + vet[n-1].first)/2.0;
        bool ok = true;
        for (int i = 0; ok && i < n; ++i){
            int x = vet[i].first, y = vet[i].second;
            if (x != midx){
                if (x < midx)
                    ok = mySet.count({midx + (midx - x), y});
                else
                    ok = mySet.count({midx + (x - midx), y});
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }

	return 0;
}
