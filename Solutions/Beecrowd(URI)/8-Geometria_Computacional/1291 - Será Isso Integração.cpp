#include <bits/stdc++.h>

#define pi 3.14159265358979323846

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	long double a;
	while(cin >> a){
        long double area = a * a;
        long double achu3 = area * (1 - sqrt(3)/4.0 - pi/6);
        long double achu2 = area - 2 * achu3 - (pi * area / 4);
        long double ans3 = 4 * achu3, ans2 = 4 * achu2;
        long double ans1 = area - (ans2 + ans3);

        cout << fixed << setprecision(3) << ans1 << ' ' << ans2 << ' ' << ans3 << '\n';
	}

	return 0;
}
