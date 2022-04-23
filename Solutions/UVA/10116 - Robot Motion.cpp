#include <bits/stdc++.h>

using namespace std;

#define pi 3.141592653589793
#define eulerconstant 0.577215664901532
#define MAXN 6050
#define LGN 17
#define LSOne(S) ((int)(S) & -(int)(S))
#define f first
#define s second
#define inf 1e9
#define inf64 4e18
#define goldenratio ((double)(1 + sqrt(5)) / 2)
#define isvalid(a_, b_, n_, m_) (a_ >= 0 && a_ < n_ && b_ >= 0 && b_ < m_)
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define rforn(i, n) for (int i = (int)(n); i >= 0; --i)
#define forr(i, l, r) for (int i = (int)(l); i < (int)(r); ++i)
#define rforr(i, l, r) for (int i = (int)(l); i >= (int)(r); --i)
#define Mid (l + ((r - l) >> 1))
#define filIn freopen("input.txt", "r", stdin);
#define filOut freopen("output.txt", "w", stdout);

typedef pair<int, int> ii;
typedef pair<int, pair<int, int>> iii;
typedef pair<char, int> ci;
typedef pair<string, int> si;
typedef pair<int, string> is;
typedef vector< int > vi;
typedef vector< long > vl;
typedef vector< char > vc;
typedef vector<pair<int, int>> vii;
typedef vector<pair< int, pair<int, int>>> viii;
typedef vector<vector<int>> vvi;
typedef long long ll;
typedef int no;

char Matrix[11][11];
int N, M, S, L, dist[11][11];

void Move(int &i, int &j, char w){
    if (w == 'N') --i;
    else if (w == 'E') ++j;
    else if (w == 'S') ++i;
    else --j;
}

void solve(){
    while(scanf("%d %d %d", &N, &M, &S), N || M || S){
        --S;
        memset(dist, 0, sizeof(dist));
        forn(i, N){
            forn(j, M){
                scanf(" %c", &Matrix[i][j]);
            }
        }
        L = 0;
        dist[L][S] = 1;
        int i = L, j = S;
        Move(L, S, Matrix[L][S]);
        bool ok = true;
        while(isvalid(L, S, N, M)){
            if (dist[L][S]){
                ok = false;
                break;
            }
            dist[L][S] = dist[i][j] + 1;
            i = L; j = S;
            Move(L, S, Matrix[L][S]);
//            cout << L << ' ' << S << '\n';
        }
        if (ok) cout << dist[i][j] << " step(s) to exit\n";
        else cout << dist[L][S] - 1 << " step(s) before a loop of "
            << dist[i][j] - dist[L][S] + 1 << " step(s)\n";
    }
}

int main(){
    //filIn; //filOut;
    ios_base::sync_with_stdio(false); cin.tie(0);
    solve();
}
