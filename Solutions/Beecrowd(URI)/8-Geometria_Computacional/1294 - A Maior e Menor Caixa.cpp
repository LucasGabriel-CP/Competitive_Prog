#include <bits/stdc++.h>

using namespace std;

double L, W;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cout << fixed << setprecision(3);
    while(cin >> L >> W){
        double Delta = (4*(L+W)) * (4*(L+W)) - 4*12*L*W;
        cout << abs(-4*(L+W)+sqrt(Delta))/24 << " 0.000 " << min(L, W)/2 << '\n';
    }

    return 0;
}
