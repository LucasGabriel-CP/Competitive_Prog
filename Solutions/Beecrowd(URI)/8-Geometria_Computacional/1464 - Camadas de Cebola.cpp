#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

struct Point{
    double x, y;
};

int orientation(Point a, Point b, Point c){
    double v = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
    if (v < 0) return -1;
    if (v > 0) return +1;
    return 0;
}

bool cw(Point a, Point b, Point c, bool inc_co){
    int ori = orientation(a, b, c);
    return ori < 0 || (inc_co && !ori);
}
bool collinear(Point a, Point b, Point c){return !orientation(a, b, c);}

void convex_hull(vector<Point>& Vet, bool include_collinear = true){
    Point p0 = *min_element(Vet.begin(), Vet.end(), [](Point a, Point b){
            return make_pair(a.y, a.x) < make_pair(b.y, b.x);
    });
    sort(Vet.begin(), Vet.end(), [&p0](const Point& a, const Point& b){
        int Ori = orientation(p0, a, b);
        if (!Ori)
            return (p0.x-a.x)*(p0.x-a.x) + (p0.y-a.y)*(p0.y-a.y)
                < (p0.x-b.x)*(p0.x-b.x) + (p0.y-b.y)*(p0.y-b.y);
        return Ori < 0;
    });
    if (include_collinear){
        int i = (int)Vet.size() - 1;
        while(i >= 0 && collinear(p0, Vet[i], Vet.back())) --i;
        reverse(Vet.begin() + i + 1, Vet.end());
    }

    vector<Point> St, newVet;
    forn(i, (int)Vet.size()){
        while(St.size() > 1 && !cw(St[St.size() - 2], St.back(), Vet[i], include_collinear)){
            newVet.push_back(St.back()); St.pop_back();
        }
        St.push_back(Vet[i]);
    }
    Vet = newVet;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int Ans, N;
    while(cin >> N, N){
        Ans = 0;
        vector<Point> Vet(N);
        forn(i, N){
            cin >> Vet[i].x >> Vet[i].y;
        }
        while(Vet.size() >= 3){
            convex_hull(Vet); ++Ans;
        }
        if (Ans % 2) cout << "Take this onion to the lab!\n";
        else cout << "Do not take this onion to the lab!\n";
    }

    return 0;
}
