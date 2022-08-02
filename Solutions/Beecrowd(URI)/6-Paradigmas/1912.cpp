//Corte minimo em barras para dar uma determinada área
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
const int MAXN = 1e4;
int N, C[MAXN];
double ans, A, Area;

float bb(){
    float m, l = 0.0000, r = (double)C[N - 1];
    int Cont = 1000;
    while(Cont--){
        m = (l + (r - l)/2);
        Area = 0.0;
        int tam = lower_bound(C, C + N, m) - C;
        forr(i, tam, N) Area += ((double)C[i] - m);
        if (abs(Area - A) <= eps) return m;
        if (A < Area) l = m;
        else r = m;
    }
    return -1.0;
}

int main(){
    while(scanf(" %d %lf", &N, &A), N || A){
        Area = 0;
        forn(i, N){
            scanf("%d", &C[i]);
            Area += (double)C[i];
        }
        if (Area == A) printf(":D\n");
        else{
            sort(C, C + N);
            ans = bb();
            if (ans == -1.0) printf("-.-\n");
            else printf("%.4lf\n", ans);
        }
    }

    return 0;
}
