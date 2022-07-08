#include <bits/stdc++.h>

using namespace std;

const int inf = (int)1e9;

struct point_i{
    int x, y;
    point_i(){ x = y = 0; }
    point_i(int x_, int y_) : x(x_), y(y_){}
    bool operator < (const point_i other) const{
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
    bool operator == (const point_i other) const{
        return x == other.x && y == other.y;
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<point_i> vet(n);
    for (point_i &p: vet) cin >> p.x >> p.y;
    sort(vet.begin(), vet.end());
    int ans = 0;
    for (int i = 0; i < n; ++i){
        int menor = inf, maior = -inf;
        for (int j = i + 1; j < n; ++j){
            if (vet[i].y > vet[j].y && maior < vet[j].y){
                maior = vet[j].y;
                ++ans;
            }
            else if (vet[i].y < vet[j].y && menor > vet[j].y){
                menor = vet[j].y;
                ++ans;
            }
        }
    }
    cout << ans << '\n';

    return 0;
}
