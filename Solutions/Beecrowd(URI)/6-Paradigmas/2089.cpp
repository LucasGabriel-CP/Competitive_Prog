#include <bits/stdc++.h>

using namespace std;

#define MAX_N 200005
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

int N, X[MAX_N];

bool cc(int ct, int v){
    if (v == 0)
        return true ;
    if (v < 0 || ct == N)
        return false;
    return cc(ct + 1, v - X[ct]) || cc(ct + 1, v);
}

void solve(){
    int V;
    while(cin >> V >> N, N || V){
        forn(i, N){
            cin >> X[i];
        }
        sort(X, X + N, [](int a, int b){ return a > b; });
        cout << (cc(0, V) ? "sim\n" : "nao\n");
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    solve();

    return 0;
}
