#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    for(int c = 1; c <= t; ++c){
        int n, m; cin >> n >> m;
        vector<int> vet(n);
        for (auto& i : vet) cin >> i;
        vector<vector<int>> AdjList(n, vector<int>());
        for (int i = 0; i < m; ++i){
            int a, b; cin >> a >>b;
            AdjList[a].push_back(b);
        }
        int u = 0, ans = 0;
        while(true){
            int maior = -1, id = -1;
            ans += vet[u];
            for(int v: AdjList[u]){
                if (vet[v] > maior){
                    maior = vet[v]; id = v;
                }
            }
            if (id == -1) break;
            u = id;
        }
        cout << "Case " << c << ": " << ans << ' ' << u << '\n';
    }

	return 0;
}
