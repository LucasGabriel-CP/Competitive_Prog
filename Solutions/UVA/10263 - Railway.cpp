#include <bits/stdc++.h>

using namespace std;
#define pi M_PI

const double eps = 1e-9;

struct point{
    double x, y;
    point(){ x = 0; y = 0; }
    point(double x_, double y_) : x(x_), y(y_){}
    bool operator < (const point other) const{
        if (fabs(x - other.x) > eps) return x < other.x;
        return y < other.y;
    }
    bool operator == (const point other) const{
        return fabs(x - other.x) > eps && fabs(y - other.y) > eps;
    }
};

double dist(const point &p1, const point &p2){
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

struct vec{
    double x, y;
    vec(double x_, double y_) : x(x_), y(y_) {}
};

vec toVec(const point &a, const point &b){ return vec(b.x-a.x, b.y-a.y); } //a->b
vec scale(const vec &v, double s){ return vec(v.x*s, v.y*s); }
point translate(const point &p, const vec &v){ return point(p.x+v.x, p.y+v.y); }
double cross(vec a, vec b){ return a.x*b.y - a.y*b.x; }
double dot(vec a, vec b){ return a.x*b.x + a.y*b.y; }
double norm_sq(vec v){ return v.x*v.x + v.y*v.y; }

struct line{
    double a, b, c;
};

double distToLine(point p, point a, point b, point &c){
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab)/norm_sq(ab);
    c = translate(a, scale(ab, u));
    return dist(p, c);
}

double distToSegment(point p, point a, point b, point &c){
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab)/norm_sq(ab);
    if (u < 0.0){
        c = point(a.x, a.y);
        return dist(p, a);
    }
    if (u > 1.0){
        c = point(b.x, b.y);
        return dist(p, b);
    }
    return distToLine(p, a, b, c);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    double mx, my, n;
    while(cin >> mx){
        cin >> my >> n;
        double menor = 1e9;
        point ans, aux;
        double x1, y1, x2, y2;
        cin >> x1 >> y1;
        for (int i = 0; i < n; ++i){
            cin >> x2 >> y2;
            double maybe = distToSegment(point(mx, my), point(x1, y1), point(x2, y2), aux);
            if  (menor > maybe){
                menor = maybe;
                ans = aux;
            }
            x1 = x2; y1 = y2;
        }
        cout << fixed << setprecision(4) << ans.x << '\n' << ans.y << '\n';
    }


    return 0;
}
