#include <bits/stdc++.h>

using namespace std;
#define pi M_PI

const double eps = 1e-9;

struct point{
    double x, y;
    point(){ x = 0.0; y = 0.0; }
    point(double x_, double y_) : x(x_), y(y_){}
    bool operator < (const point other) const{
        if (fabs(x - other.x) > eps) return x < other.x;
        return y < other.y;
    }
    bool operator == (const point other) const{
        return fabs(x - other.x) > eps && fabs(y - other.y) > eps;
    }
};

struct vec{
    double a, b, c;
    vec() { }
    //Usando vec como segmento
    vec(point p, point q){
        a = p.y - q.y;
        b = q.x - p.x;
        c = -a * p.x - b * p.y;
        norm();
    }
    void norm(){
        double z = sqrt(a * a + b * b);
        if (abs(z) > eps)
            a /= z, b /= z, c /= z;
    }
    double dist(point p) const { return a * p.x + b * p.y + c; }
};

double det(double a, double b, double c, double d){ return a * d - b * c; } //determinante

inline bool betw(double l, double r, double x){ return min(l, r) <= x + eps && x <= max(l, r) + eps; }

inline bool intersect_1d(double a, double b, double c, double d){
    if (a > b)  swap(a, b);
    if (c > d)  swap(c, d);
    return max(a, c) <= min(b, d) + eps;
}

bool intersect(point a, point b, point c, point d, point& left, point& right){ //segmentos (a, b) e (c, d)
    if (!intersect_1d(a.x, b.x, c.x, d.x) || !intersect_1d(a.y, b.y, c.y, d.y)) return false;
    vec m(a, b);
    vec n(c, d);
    double zn = det(m.a, m.b, n.a, n.b);
    if (abs(zn) < eps){
        if (abs(m.dist(c)) > eps || abs(n.dist(a)) > eps)   return false;
        if (b < a)  swap(a, b);
        if (d < c)  swap(c, d);
        left = max(a, c);
        right = min(b, d);
        return true;
    }
    else{
        left.x = right.x = -det(m.c, m.b, n.c, n.b) / zn;
        left.y = right.y = -det(m.a, m.c, n.a, n.c) / zn;
        return betw(a.x, b.x, left.x) && betw(a.y, b.y, left.y) &&
                betw(c.x, d.x, left.x) && betw(c.y, d.y, left.y);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    while(cin >> n, n){
        vector<pair<point, point>> vet(n);
        for (int i = 0; i < n; ++i){
            int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
            vet[i] = {point(x1, y1), point(x2, y2)};
        }
        set<pair<double, double>> mySet;
        vector<int> have(n, false);
        for (int i = 0; i < n; ++i){
            for (int j = i + 1; j < n; ++j){
                point p1, p2;
                if (intersect(vet[i].first, vet[i].second, vet[j].first, vet[j].second, p1, p2)){
                    mySet.insert({p1.x, p1.y});
                    have[i] = have[j] = true;
                }
            }
            if (!have[i]){
                mySet.insert({vet[i].first.x, vet[i].first.y});
                mySet.insert({vet[i].second.x, vet[i].second.y});
            }
        }
        cout << (int)mySet.size() << '\n';
    }

    return 0;
}
