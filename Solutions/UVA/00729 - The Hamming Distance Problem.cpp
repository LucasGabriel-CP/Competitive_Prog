#include <bits/stdc++.h>

#ifdef PIZZA
__attribute__((destructor))static void __destroy__(){std::cerr<<"\nElapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";}
#endif

using namespace std;

const int maxn = 1e6 + 50;
set<string> ans;
vector<bool> used;

void f(int n, int k, string str){
    if (k == n || k < 0) return;
    if (str[k] == '0'){ f(n, k+1, str); return; }
    for (; k > 0; --k){
        if (str[k-1] == '1'){
            f(n, k+1, str);
            return;
        }
        used[k] = false;
        used[k-1] = true;
        str[k] = '0';
        str[k-1] = '1';
        if (!ans.count(str)){
            ans.insert(str);
            f(n, k+1, str);
        }
    }
}

int main(){
    int t; cin >> t;
    while(t--){
        ans.clear();
        int n, h; cin >> n >> h;
        used.assign(n+1, false);
        string str(n, '0');
        for (int i = n-h; i < n; ++i) str[i] = '1';
        ans.insert(str);
        f(n, n-h, str);
        for (string s: ans) cout << s << '\n';
        if (t) cout << '\n';
    }

	return 0;
}
