#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-9, pi = 2*acos(0.0);

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    while(n--){
        int d, l; cin >> d >> l;
        double a = (double)l/2.0;
        double c = (double)d/2.0;
        double b = sqrt(a*a - c*c);
        double ans = pi * a * b;
        cout << fixed << setprecision(3) << ans << '\n';
    }

    return 0;
}
