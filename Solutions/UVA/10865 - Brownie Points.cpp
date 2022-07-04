#include <bits/stdc++.h>

using namespace std;

const int maxn = 125, inf = 1e9, mod = 1000007;

struct Point{
    int x, y;
    Point(int x_, int y_){ x = x_; y = y_; }
    Point(){ x = 0; y = 0; }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    while(cin >> n, n){
        vector<Point> vet(n);
        for (int i = 0; i < n; ++i) cin >> vet[i].x >> vet[i].y;
        Point mid = vet[n/2];
        int S, O;
        S = O = 0;
        for (int i = 0; i < n; ++i){
            if (vet[i].x > mid.x && vet[i].y > mid.y || vet[i].x < mid.x && vet[i].y < mid.y) ++S;
            else if (vet[i].x != mid.x && vet[i].y != mid.y) ++O;
        }
        cout << S << ' ' << O << '\n';
    }

    return 0;
}
