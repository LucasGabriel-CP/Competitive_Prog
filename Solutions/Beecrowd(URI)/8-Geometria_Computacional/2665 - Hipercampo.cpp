#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1005, inf = 1e5;

struct Point{
    int x, y, id;
    Point(){ x = y = id = 0; }
    Point(int _x, int _y): x(_x), y(_y) {}
};

struct Triangulo{
    Point pt1, pt2, pt3;
    Triangulo(Point _pt1, Point _pt2, Point _pt3){
        pt1 = _pt1;
        pt2 = _pt2;
        pt3 = _pt3;
    }
    int area(){
        return abs((pt1.x*(pt2.y-pt3.y) + pt2.x*(pt3.y-pt1.y)+ pt3.x*(pt1.y-pt2.y)));
    }
};

bool isIn(Triangulo t, Point pt0){
    int A = t.area();
    int A1 = Triangulo(pt0, t.pt2, t.pt3).area();
    int A2 = Triangulo(t.pt1, pt0, t.pt3).area();
    int A3 = Triangulo(t.pt1, t.pt2, pt0).area();
    return (A == A1 + A2 + A3);
}

int dp[MAXN], n;

int backtrac(vector<Point> &Pontos, Point a, Point b, Point p0, int cur){
    auto& d = dp[cur];
    if (d != -1) return d;
    int cnt = 0, aux, op1 = -1;
    for (Point i : Pontos){
        if (i.id != p0.id && isIn(Triangulo(a, b, p0), i)){
            aux = 1 + backtrac(Pontos, a, b, i, i.id);
            op1 = max(op1, aux);
            ++cnt;
        }
    }
    if (!cnt) return d = 1;
    return d = max(op1, aux);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    Point a, b;
    cin >> n >> a.x >> b.x;
    vector<Point> Pontos(n);
    for (int i = 0; i < n; ++i){
        cin >> Pontos[i].x >> Pontos[i].y;
        Pontos[i].id = i;
        dp[i] = -1;
    }
    int ans = -1;
    for (Point i : Pontos){
        ans = max(ans, backtrac(Pontos, a, b, i, i.id));
    }
    //for (int i = 0; i < n; ++i) cout << dp[i] << '\n';
    cout << ans << '\n';

	return 0;
}
