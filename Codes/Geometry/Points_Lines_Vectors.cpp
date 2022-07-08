#include <bits/stdc++.h>

using namespace std;
#define pi M_PI

const double eps = 1e-9;

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

double DEG_to_RAD(double d){ return d*pi/180.0; }
double RAD_to_DEG(double r){ return r*180.0/pi; }

point rotate(const point &p, double theta){ //CCW
    if (theta == 90) return point(p.y, -p.x);
    double r = DEG_to_RAD(theta);
    return point(p.x*cos(r) - p.y*sin(r),p.x*sin(r) + p.y*cos(r));
}

struct line{
    double a, b, c;
};

void pointsToLine(const point &p1, const point &p2, line &l){
    if (fabs(p1.x - p2.x) < eps) l = {1.0, 0.0, -p1.x}; //b = 0.0 -> vertical
    else l = {-(double)(p1.y-p2.y)/(p1.x-p2.x), 1.0, -(double)(l.a*p1.x)-p1.y};
}

void slopeToLine(const point &p, double slope, line &l){
    l.a = -slope;
    l.b = 1.0;
    l.c = -((l.a*p.x) + (l.b*p.y));
}

bool areParallel(line l1, line l2){
    return (fabs(l1.a-l2.a) < eps) && (fabs(l1.b-l2.b) < eps);
}

bool areSame(line l1, line l2){
    return areParallel(l1, l2) && (fabs(l1.c-l2.c) < eps);
}

bool areIntersect(line l1, line l2, point &p){
    if(areParallel(l1, l2)) return false;
    p.x = (l2.b*l1.c - l1.b*l2.c)/(l2.a*l1.b - l1.a*l2.b);
    if (fabs(l1.b) > eps) p.y = -(l1.a*p.x + l1.c);
    else p.y = -(l2.a*p.x + l2.c);
    return true;
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
inline bool betw(double l, double r, double x){ return min(l, r) <= x + eps && x <= max(l, r) + eps; }

inline bool intersect_1d(double a, double b, double c, double d){
    if (a > b)  swap(a, b);
    if (c > d)  swap(c, d);
    return max(a, c) <= min(b, d) + eps;
}

bool areIntersect(point a, point b, point c, point d, point& left, point& right){ //segmentos (a, b) e (c, d)
    if (!intersect_1d(a.x, b.x, c.x, d.x) || !intersect_1d(a.y, b.y, c.y, d.y)) return false;
    vec m(a, b);
    vec n(c, d);
    double zn = det(m.x, m.y, n.x, n.y);
    if (abs(zn) < eps){
        if (abs(m.dist(c)) > eps || abs(n.dist(a)) > eps)   return false;
        if (b < a)  swap(a, b);
        if (d < c)  swap(c, d);
        left = max(a, c);
        right = min(b, d);
        return true;
    }
    else{
        left.x = right.x = -det(m.z, m.y, n.z, n.y) / zn;
        left.y = right.y = -det(m.x, m.z, n.x, n.z) / zn;
        return betw(a.x, b.x, left.x) && betw(a.y, b.y, left.y) &&
                betw(c.x, d.x, left.x) && betw(c.y, d.y, left.y);
    }
}

double angle(const point &a, const point &o, const point &b){ //return angle in radians
    vec oa = toVec(o, a), ob = toVec(o, b);
    return acos(dot(oa, ob)/sqrt(norm_sq(oa)*norm_sq(ob)));
}

// > 0 -> left turn, == 0 -> collinear, < 0 -> right turn
bool ccw(point p, point q, point r){
    return cross(toVec(p, q), toVec(p, r)) > eps;
}
bool collinear(point p, point q, point r){
    return fabs(cross(toVec(p, q), toVec(p, r))) < eps;
}

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

    return 0;
}
