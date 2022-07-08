#include <iostream>
#include <stdlib.h>

using namespace std;

const int MAXN = 105, inf = 1e5;

struct Point{
    int x, y;
};
Point triangulo[3], ptsB[MAXN], ptsW[MAXN];

int area(int x1, int y1, int x2, int y2, int x3, int y3){
   return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2)));
}

bool isIn(Point p1, Point p2, Point p3, Point pt){
    int A = area(p1.x, p1.y, p2.x, p2.y, p3.x, p3.y);
    int A1 = area(pt.x, pt.y, p2.x, p2.y, p3.x, p3.y);
    int A2 = area(p1.x, p1.y, pt.x, pt.y, p3.x, p3.y);
    int A3 = area (p1.x, p1.y, p2.x, p2.y, pt.x, pt.y);
    if (!A1 || !A2 || !A3) return false;
    return (A == A1 + A2 + A3);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, m, x, y;
    int ans = 0, aux;
	while(cin >> n >> m){
        for(int i = 0; i < n; ++i){
            cin >> ptsB[i].x >> ptsB[i].y;
        }
        for(int i = 0; i < m; ++i)
            cin >> ptsW[i].x >> ptsW[i].y;
        ans = 0;
        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n; ++j){
                for(int k = j + 1; k < n; ++k){
                    aux = 0;
                    for(int l = 0; l < m; ++l)
                        aux += (isIn(ptsB[i], ptsB[j], ptsB[k], ptsW[l]));
                    ans += aux * aux;
                }
            }
        }
        cout << ans << '\n';
	}

	return 0;
}
