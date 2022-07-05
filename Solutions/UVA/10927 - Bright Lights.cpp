#include <bits/stdc++.h>

using namespace std;

const int maxn = 125, inf = 1e9, mod = 1000007;
const double eps = 1e-11;

struct Point{
    double x, y, slope;
    int z;
    Point(){x = 0.0; y = 0.0; z = 0; slope = 0.0; }
    Point(double x_, double y_, int z_) : x(x_), y(y_), z(z_){}
    bool operator < (Point other) const{
        if (x && other.x && fabs(slope - other.slope) > eps)
            return slope < other.slope;
        return (long long)x*x + (long long)y*y < (long long)other.x*other.x + (long long)other.y*other.y;
    }
};

void solve(vector<Point> vet, vector<pair<int, int>> &ans){
    double ant;
    int h, antx;
    if (vet.front().x) ant = vet.front().slope;
    antx = (vet.front().x ? vet.front().x : vet.front().y);
    h = vet.front().z;
    for (int i = 1; i < (int)vet.size(); ++i){
        Point& p = vet[i];
        if (p.x && (fabs(ant - p.slope) > eps) || antx > 0 && (p.x ? p.x : p.y) < 0 || antx < 0 && (p.x ? p.x : p.y) > 0){
            ant = p.slope;
            antx = p.x ? p.x : p.y;
            h = p.z;
        }
        else{
            if (h < p.z) h = p.z;
            else ans.push_back({p.x, p.y});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, c = 1;
    while(cin >> n, n){
        vector<Point> vet, vetyneg, vetxneg, vetypos, vetxpos;
        vector<pair<int, int>> ans;
        for (int i = 0; i < n; ++i){
            Point p; cin >> p.x >> p.y >> p.z;
            if (!p.x){
               if(p.y > 0) vetypos.push_back(p);
               else vetyneg.push_back(p);
            }
            else{
                p.slope = p.y/p.x;
                if (!p.y){
                   if(p.x > 0) vetxpos.push_back(p);
                   else vetxneg.push_back(p);
                }
                else vet.push_back(p);
            }
        }
        sort(vetypos.begin(), vetypos.end());
        sort(vetyneg.begin(), vetyneg.end());
        sort(vetxneg.begin(), vetxneg.end());
        sort(vetxpos.begin(), vetxpos.end());
        sort(vet.begin(), vet.end());
        double ant;
        int h, antx;
        if (!vet.empty()) solve(vet, ans);
        if (!vetxpos.empty()) solve(vetxpos, ans);
        if (!vetxneg.empty()) solve(vetxneg, ans);
        if (!vetypos.empty()) solve(vetypos, ans);
        if (!vetyneg.empty()) solve(vetyneg, ans);
        cout << "Data set " << c++ << ":\n";
        if (ans.empty()) cout << "All the lights are visible.\n";
        else{
            cout << "Some lights are not visible:\n";
            sort(ans.begin(), ans.end());
            for (int i = 0; i < (int)ans.size() - 1; ++i)
                cout << "x = " << ans[i].first << ", y = " << ans[i].second << ";\n";
            cout << "x = " << ans.back().first << ", y = " << ans.back().second << ".\n";
        }
    }

    return 0;
}
