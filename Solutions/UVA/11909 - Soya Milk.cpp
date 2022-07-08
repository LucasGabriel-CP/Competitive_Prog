#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-9, pi = 2*acos(0.0);

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int l, w, h, th;
    double a, alpha, b, c, sTheta, base, hei, tri;
    while(cin >> l >> w >> h >> th){
        if (l * tan(th * pi/180.0) <= h){
            alpha = 90.0 - th;
            sTheta = sin(th*pi/180.0);
            a = l;
            b = a/sin(alpha*pi/180.0)*sTheta;
            c = a/sin(alpha*pi/180.0);
            tri = b*a*w*0.5;
            double retH = h - b;
            double ret1 = retH * l * w;
            cout << fixed << setprecision(3) << ret1 + tri << " mL\n";
        }
        else{
            a = h;
            alpha = 90 - th;
            double sinA = a/sin(th*pi/180.0);
            c = sinA;
            b = sinA * sin(alpha*pi/180.0);
            tri = b*a*w*0.5;
            cout << fixed << setprecision(3) << tri << " mL\n";
        }
    }

    return 0;
}
