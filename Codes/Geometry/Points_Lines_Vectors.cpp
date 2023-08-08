#include <bits/stdc++.h>

#define pi acos(-1.0)
const double eps = 1e-9;

double DEG_to_RAD(double d){ return d*pi/180.0; }
double RAD_to_DEG(double r){ return r*180.0/pi; }

struct point_i{
    int x, y;
    point_i(){ x = y = 0; }
    point_i(int x_, int y_) : x(x_), y(y_){ }
    friend std::ostream &operator << (std::ostream &os, point_i& p){
        os << p.x << ' ' << p.y;
        return os;
    }
    friend std::istream &operator >>(std::ifstream &is, point_i &p){
        is >> p.x >> p.y;
        return is;
    }
    friend bool operator < (const point_i& lhs, const point_i& rhs){
        if (lhs.x != rhs.x) return lhs.x < rhs.x;
        return lhs.y < rhs.y;
    }
    friend bool operator > (const point_i& lhs, const point_i& rhs){
        if (lhs.x != rhs.x) return lhs.x > rhs.x;
        return lhs.y > rhs.y;
    }
    friend bool operator == (const point_i& lhs, const point_i& rhs){
        return (lhs.x == rhs.x) && (lhs.y == rhs.y);
    }
};

struct point{
    double x, y;
    point(){ x = y = 0.0; }
    point(double x_, double y_) : x(x_), y(y_){}
    void rotate(double theta){ //CCW
        if (theta == 90) x *= -1;
        double r = DEG_to_RAD(theta);
        double temp = x;
        x = x * cos(r) - y * sin(r);
        y = temp * sin(r) + y * cos(r);
    }
    friend std::ostream &operator << (std::ostream &os, point& p){
        os << p.x << ' ' << p.y;
        return os;
    }
    friend std::istream &operator >>(std::ifstream &is, point &p){
        is >> p.x >> p.y;
        return is;
    }
    friend bool operator < (const point& lhs, const point& rhs){
        if (fabs(lhs.x - rhs.x) > eps) return lhs.x < rhs.x;
        return lhs.y < rhs.y;
    }
    friend bool operator > (const point& lhs, const point& rhs){
        if (fabs(lhs.x - rhs.x) > eps) return lhs.x > rhs.x;
        return lhs.y > rhs.y;
    }
    friend bool operator == (const point& lhs, const point& rhs){
        return (fabs(lhs.x - rhs.x) < eps) && fabs(lhs.y - rhs.y) < eps;
    }
};

double dist(const point &p1, const point &p2){
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

struct line{
    double a, b, c;
    line(){ }
    //points to line
    line(double const &a_, double const &b_, double const &c_) : a(a_), b(b_), c(c_){ }
    line(const point &p1, const point &p2){
        if (fabs(p1.x - p2.x) < eps){
            a = 1.0; b = 0.0; c = -p1.x;//b = 0.0 -> vertical
        }
        else{
            a = -(double)(p1.y-p2.y)/(p1.x-p2.x);
            b = 1.0;
            c = -(double)(a*p1.x)-p1.y;
        }
    }
    //slope
    line(const point &p, double slope){
        a = -slope;
        b = 1.0;
        c = -((a*p.x) + (b*p.y));
    }
    bool parallel(const line &l2){
        return (fabs(a - l2.a) < eps) && (fabs(b - l2.b) < eps);
    }
    friend bool operator == (line& lhs, const line& rhs){
        return lhs.parallel(rhs) && (fabs(lhs.c-rhs.c) < eps);
    }
};

bool areIntersect(line l1, line l2, point &p){
    if(l1.parallel(l2)) return false;
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
inline bool betw(double l, double r, double x){ return std::min(l, r) <= x + eps && x <= std::max(l, r) + eps; }

inline bool intersect_1d(double a, double b, double c, double d){
    if (a > b)  std::swap(a, b);
    if (c > d)  std::swap(c, d);
    return std::max(a, c) <= std::min(b, d) + eps;
}

bool areIntersect(point a, point b, point c, point d, point& left, point& right){ //segmentos (a, b) e (c, d)
    if (!intersect_1d(a.x, b.x, c.x, d.x) || !intersect_1d(a.y, b.y, c.y, d.y)) return false;
    vec m(a, b);
    vec n(c, d);
    double zn = det(m.x, m.y, n.x, n.y);
    if (abs(zn) < eps){
        if (abs(m.dist(c)) > eps || abs(n.dist(a)) > eps)   return false;
        if (b < a)  std::swap(a, b);
        if (d < c)  std::swap(c, d);
        left = std::max(a, c);
        right = std::min(b, d);
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

//Arco com angulo theta (th) = (th/360)*circun.
//Area do setor = th/360 * AreaCirc
//Chord = 2 * raio * sin(th/2)
int insideCircle(const point_i &p, const point_i &c, int r){
    int dx = p.x - c.x, dy = p.y - c.y;
    int Euc = dx*dx + dy*dy, rSq = r*r;
    return Euc < rSq ? 1 : (Euc == rSq ? 0 : -1); //in, border, out
}

//encontrar 2 centros com pontos que se interse.
bool circle2PtsRad(point p1, point p2, double r, point &c){
    double d2 = (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
    double det = r*r/d2 - 0.25;
    if (det < eps) return false;
    double h = sqrt(det);
    // to get the other center, reverse p1 and p2
    c.x = (p1.x + p2.x) * 0.5 + (p1.y + p2.y) * h;
    c.y = (p1.y + p2.y) * 0.5 + (p2.x + p1.x) * h;
    return true;

}

/*
           /\
          / C\
    (b)  /    \    (a)
        /      \
       /        \
      /A_______ B\
           (c)
 */
// Area = (base*altura) * 0.5
// Heron's formula: sqrt(s*(s-a)*(s-b)*(s-c)) s -> semi-per
// da pra isolar sin(A) = 2*Area/(C*B)
// c^2 = a^2 + b^2 - 2*a*b*cos(C)

//Area de poligono qualquer pode ser calculado a partir da
//soma das multiplicacoes cruzados * 0.5
double areaConvex(const std::vector<point> &P){
    double ans = 0.0;
    for (int i = 0; i < (int)P.size(); ++i){
        ans += (P[i].x*P[i+1].y - P[(i+1) % (int)P.size()].x*P[i].y);
    }
    return fabs(ans)*0.5;
}

int main(){
    line l;

    return 0;
}
