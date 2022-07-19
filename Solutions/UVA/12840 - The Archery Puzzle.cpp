#include <bits/stdc++.h>

#ifdef PIZZA
__attribute__((destructor))static void __destroy__(){std::cerr<<"\nElapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";}
#endif

using namespace std;

const int maxn = 55, inf = 1e9;
int n, p, vet[maxn];
vector<int> ans;

int f(int cur, int tot, vector<int> aux){
    if (cur == n || !ans.empty() && (int)aux.size() > (int)ans.size()) return inf;
    if (tot == p){
        if (ans.empty() || (int)aux.size() < (int)ans.size()) ans = aux;
        return (int)aux.size();
    }
    int op1 = inf, op2 = inf;
    if (tot + vet[cur] <= p){
        aux.push_back(vet[cur]);
        op1 = f(cur, tot + vet[cur], aux);
        aux.pop_back();
    }
    op2 = f(cur + 1, tot, aux);
    return min(op1, op2);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    for (int tc = 1; tc <= t; ++tc){
        cin >> n >> p;
        for (int i = 0; i < n; ++i) cin >> vet[i];
        cout << "Case " << tc << ": ";
        vector<int> aux;
        ans.clear();
        sort(vet, vet + n, greater<int>());
        if (f(0, 0, aux) < inf){
            cout << '[' << (int)ans.size() << ']';
            for (int &i: ans) cout << ' ' << i;
            cout << '\n';
        }
        else cout << "impossible\n";
    }

	return 0;
}
