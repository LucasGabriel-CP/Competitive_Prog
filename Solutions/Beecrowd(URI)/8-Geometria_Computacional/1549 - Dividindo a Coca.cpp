#include <bits/stdc++.h>

using namespace std;

#define pi 3.141592653589793
typedef long long ll;

int b, B, H, N;
ll L;

ll calcVol(int R, int r, double h){
    double R2 = r + h * (R - r) / H;
    return ((pi * h / 3.00) * (R2 * R2 + R2 * r + r * r)) * 1000;
}

double binsearch(){
    double h = H / 2.0, l = 0, r = H, m;
    while((int)(l*1000) != (int)(r*1000)){
        m = (l + r) / 2;
        ll Vpossi = calcVol(B, b, m);
        if (Vpossi * N > L){
            r = m;
        }
        else if (Vpossi * N == L){
            break;
        }
        else l = m;
    }
    return m;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cout << fixed << setprecision(2);
    int C;  cin >> C;
    while(C--){
        cin >> N >> L; L *= 1000;
        cin >> b >> B >> H;
        cout << binsearch() << '\n';
    }

    return 0;
}
