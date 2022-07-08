#include <bits/stdc++.h>

using namespace std;
#define pi M_PI

const double eps = 1e-9;

struct point{
    double x, y;
    point(){ x = y = 0.0; }
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
    double x, y, z;
    vec() { x = y = z = 0.0; }
    vec(double x_, double y_): x(x_), y(y_) { }
    //Usando vec como segmento
    vec(point p, point q){
        x = p.y - q.y;
        y = q.x - p.x;
        z = -x * p.x - y * p.y;
        norm();
    }
    void norm(){
        double z_ = sqrt(x * x + y * y);
        if (abs(z_) > eps)
            x /= z_, y /= z_, z /= z_;
    }
    double dist(point p) const { return x * p.x + y * p.y + z; }
};

vec toVec(const point &a, const point &b){ return vec(b.x-a.x, b.y-a.y); } //a->b
vec scale(const vec &v, double s){ return vec(v.x*s, v.y*s); }
point translate(const point &p, const vec &v){ return point(p.x+v.x, p.y+v.y); }
double cross(vec a, vec b){ return a.x*b.y - a.y*b.x; }
double det(double a, double b, double c, double d){ return a * d - b * c; } //determinante
double dot(vec a, vec b){ return a.x*b.x + a.y*b.y; }
double norm_sq(vec v){ return v.x*v.x + v.y*v.y; }

double distToLine(point p, point a, point b, point &c){
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab)/norm_sq(ab);
    c = translate(a, scale(ab, u)); //a + u*ab
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
    int n;
    while(cin >> n){
        vector<point> vet(n);
        point ori, aux; cin >> ori.x >> ori.y;
        for (point &p: vet) cin >> p.x >> p.y;
        double menor = 1e9;
        for (int i = 0; i < n - 1; ++i){
            menor = min(menor, distToSegment(ori, vet[i], vet[i + 1], aux));
        }
        cout << fixed << setprecision(3) << min(menor, distToSegment(ori, vet.back(), vet.front(), aux)) << '\n';
    }

    return 0;
}
