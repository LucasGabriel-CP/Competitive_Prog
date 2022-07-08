#include <bits/stdc++.h>

using namespace std;

double m1, m2, m3, sm;

void solve(){
    while(cin >> m1 >> m2 >> m3){
        if (m1 >= m2 + m3 || m2 >= m1 + m3 || m3 >= m1 + m2) cout << "-1.000" << '\n';
        else{
            sm = (m1 + m2 + m3) / 2;
            cout << 4/3.0 * sqrt(sm * (sm - m1) * (sm - m2) * (sm - m3)) << '\n';
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cout << fixed << setprecision(3);
    solve();

    return 0;
}
