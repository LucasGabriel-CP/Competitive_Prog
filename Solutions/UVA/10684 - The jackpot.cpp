#include <bits/stdc++.h>

#ifdef PIZZA
__attribute__((destructor))static void __destroy__(){std::cerr<<"\nElapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";}
#endif

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    while(cin >> n, n){
        vector<int> vet(n);
        for (int &i: vet) cin >> i;
        int ans = 0, aux = 0;
        for (int i: vet){
            if (aux + i >= 0){
                aux += i;
                ans = max(aux, ans);
            }
            else aux = 0;
        }
        if (ans <= 0) cout << "Losing streak.\n";
        else cout << "The maximum winning streak is " << ans << ".\n";
    }

    return 0;
}
