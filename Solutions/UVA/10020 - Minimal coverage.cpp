//Da pra fazer guloso tbm
#include <bits/stdc++.h>

#ifdef PIZZA
__attribute__((destructor))static void __destroy__(){std::cerr<<"\nElapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";}
#endif

using namespace std;

const int maxn = 1e5+50, inf = 1e9;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int m, t; cin >> t;
    while(t--){
        pair<int, int> p;
        vector<pair<int, int>> vet, ans;
        cin >> m;
        while(cin >> p.first >> p.second, p.first || p.second){
            if (p.second > 0 && p.first <= m){
                vet.push_back(p);
            }
        }
        sort(vet.begin(), vet.end(), [](pair<int, int> a,  pair<int, int> b){
                                        if (a.first < 0) a.first = 0;
                                        if (b.first < 0) b.first = 0;
                                        if (a.first != b.first) return a.first < b.first;
                                        return a.second < b.second;
                                    });
        int last = 0, aux;
        for (int i = 0; i < (int)vet.size() && last < m; ){
            if (vet[i].first - last > 0){
                ans.clear(); break;
            }
            int aux = vet[i].first > 0 ? vet[i].first : 0;
            while(i < (int)vet.size()){
                int comp =  vet[i].first > 0 ? vet[i].first : 0;
                if (comp != aux) break;
                ++i;
            }
            --i;
            ans.push_back(vet[i]);
            last = vet[i].second;
            int id = i++, maior = -1;
            pair<int, int> cover;
            for (; i < (int)vet.size(); ++i){
                if (vet[i].first > last) break;
                if (vet[i].second < last) continue;
                if (vet[i].second > maior){
                    id = i;
                    maior = vet[i].second;
                }
            }
            i = id;
            if (vet[i].second == last) break;
        }
        if (last < m) ans.clear();
        sort(ans.begin(), ans.end());
        cout << ans.size() << '\n';
        for (pair<int, int> i: ans) cout << i.first << ' ' << i.second << '\n';
        if (t) cout << '\n';
    }

    return 0;
}
