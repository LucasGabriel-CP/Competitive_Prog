#include <bits/stdc++.h>

using namespace std;
#define pi M_PI

const double eps = 1e-7;

struct point_i{
    int x, y;
    point_i(){ x = 0; y = 0; }
    point_i(int x_, int y_) : x(x_), y(y_){}
    bool operator < (const point_i other) const{
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
    bool operator == (const point_i other) const{
        return x == other.x && y == other.y;
    }
};

double DEG_to_RAD(double d){ return d*pi/180.0; }
double RAD_to_DEG(double r){ return r*180.0/pi; }

point_i rotate90(const point_i &p, double theta){
    double r = DEG_to_RAD(theta);
    return point_i(p.y, -p.x);
}

double dist(const point_i &p1, const point_i &p2){
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

int n;

bool teste(vector<point_i> &ori, vector<point_i> &prob){
    double d = dist(ori.front(), prob.front());
    for (int i = 1; i < n; ++i){
        double aux = dist(ori[i], prob[i]);
        if (fabs(d - aux) > eps) return false;
    }
    return true;
}

void change(vector<point_i> &vet){
    for (point_i &p: vet){
        p = rotate90(p, 90);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while(t--){
        cin >> n;
        vector<point_i> ori(n), prob(n);
        for (point_i &p: ori) cin >> p.x >> p.y;
        for (point_i &p: prob) cin >> p.x >> p.y;
        sort(ori.begin(), ori.end());
        bool ans = false;
        for (int i = 0; i < 4 && !ans; ++i){
            sort(prob.begin(), prob.end());
            ans = teste(ori, prob);
            change(prob);
        }
        ans ? cout << "MATCHED\n" : cout << "NOT MATCHED\n";
    }

    return 0;
}
