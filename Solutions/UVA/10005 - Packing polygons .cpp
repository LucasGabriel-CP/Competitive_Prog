#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-9;

struct point{
    double x, y;
    point(){ x = y = 0.0; }
    point(double x_, double y_) : x(x_), y(y_){}
};

double dist(const point &p1, const point &p2){
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

bool isInside(const point &p, const point &c, double r){
    if (dist(p, c) - 4 * r * r > eps) return false;
    double dx = p.x - c.x, dy = p.y - c.y;
    double Euc = dx*dx + dy*dy, R = r*r;
    return Euc - R < eps;
}

void circle2PtsRad(point p1, point p2, double r, point &c){
    double d2 = (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
    double det = r*r/d2 - 0.25;
    double h = sqrt(det);
    c.x  = (p1.x + p2.x) * 0.5 + (p1.y-p2.y)*h;
    c.y  = (p1.y + p2.y) * 0.5 + (p2.x-p1.x)*h;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    while(cin >> n, n){
        vector<point> vet(n);
        point c;
        for (point &p: vet) cin >> p.x >> p.y;
        double r; cin >> r;
        if (n == 1){ cout << "The polygon can be packed in the circle.\n"; continue; }
        bool ans = false;
        for (int i = 0; i < n && !ans; ++i){
            for (int j = 0; j < n && !ans; ++j){
                if (i == j) continue;
                circle2PtsRad(vet[i], vet[j], r, c);
                for (point &p: vet){
                    if (!isInside(p, c, r)){
                        ans = false; break;
                    }
                    ans = true;
                }
            }
        }
        cout << (ans ? "The polygon can be packed in the circle.\n" : "There is no way of packing that polygon.\n");
    }

    return 0;
}
