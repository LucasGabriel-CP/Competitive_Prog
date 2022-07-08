#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    while(cin >> n >> m){
        double s1 = 360.0/(double)n;
        double s2 = 360.0/(double)(n + m);
        double ans = 0.0;
        for (double p = s1, q = s2; q < 360; q += s2){
            if (p == q) p += s1;
            else if (q > p){
                ans += min(fabs(p-q), fabs(q - s2 - p))*10000.0/360.0;
                p += s1;
            }
        }

        cout << fixed << setprecision(4)<< ans << '\n';
    }

    return 0;
}
