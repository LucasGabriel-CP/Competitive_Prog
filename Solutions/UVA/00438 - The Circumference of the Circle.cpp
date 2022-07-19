#include <bits/stdc++.h>

#ifdef PIZZA
__attribute__((destructor))static void __destroy__(){std::cerr<<"\nElapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";}
#endif

using namespace std;

const long double pi = 3.141592653589793, eps = 1e-9;

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

double area(double a, double b, double c){
    double s = 0.5 * (a + b + c);
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

double rCircumCircle(double ab, double bc, double ca){
    return ab * bc * ca / (4.0 * area(ab, bc, ca));
}

double rCircumCircle(const point &a, const point &b, const point &c){
    return rCircumCircle(dist(a, b), dist(b, c), dist(c, a));
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    point a, b, c;
    while(cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y){
        double r = rCircumCircle(a, b, c);
        cout << fixed << setprecision(2) << 2 * pi * r << '\n';
    }

    return 0;
}
