#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1005, inf = 1e5;

struct Point{
    int x, y;
    Point(){ x = y = 0; }
    Point(int _x, int _y): x(_x), y(_y) {}
    long double dist(Point p){
        return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
    }
};

struct Line{
    int a, b, c;
    Point pt1, pt2;
    Line(){
        a = b = c = 0;
    }
    Line(Point _pt1, Point _pt2){
        pt1 = _pt1; pt2 = _pt2;
        a = pt1.y - pt2.y;
        b = pt2.x - pt1.x;
        c = pt1.x * pt2.y - pt1.y * pt2.x;
    }
    long double distPt(Point p){
        return abs(a * p.x + b * p.y + c)/sqrt(a * a + b * b);
    }
};

Line linha[MAXN];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, l, h, yi, xf, yf;
    long double ans, aux;
    while(cin >> n){
        cin >> l >> h;
        for (int i = 1; i <= n; ++i){
            cin >> yi >> xf >> yf;
            if (i & 1){
                linha[i] = Line(Point(0, yi), Point(xf, yf));
            }
            else{
                linha[i] = Line(Point(xf, yf), Point(l, yi));
            }
        }
        ans = inf;
        for (int i = 1; i < n; ++i){
            if (i & 1){
                if (linha[i].pt2.x < linha[i + 1].pt1.x)
                    ans = min(ans, linha[i].pt2.dist(linha[i + 1].pt1));
                else
                    ans = min(ans, linha[i + 1].distPt(linha[i].pt2));
                ans = min(ans, (long double)abs(linha[i].pt2.x - l));
            }
            else{
                if (linha[i].pt1.x > linha[i + 1].pt2.x)
                    ans = min(ans, linha[i].pt1.dist(linha[i + 1].pt2));
                else
                    ans = min(ans, linha[i + 1].distPt(linha[i].pt1));
                ans = min(ans, (long double)linha[i].pt1.x);
            }
        }
        if (n & 1)
            ans = min(ans, (long double)abs(linha[n].pt2.x - l));
        else
            ans = min(ans, (long double)linha[n].pt1.x);
        cout << fixed << setprecision(2) << ans << '\n';
    }

	return 0;
}
