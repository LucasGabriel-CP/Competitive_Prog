#include <bits/stdc++.h>

using namespace std;

#define pi 3.141592653589793
#define eulerconstant 0.577215664901532
#define MAXN 1050
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

int N, M, Rows, R, Q, W, dist[MAXN][MAXN];
bool Bombs[MAXN][MAXN];
int x[4] = {1, -1, 0, 0}, y[4] = {0, 0, 1, -1};

int bfs(int ox, int oy, int dx, int dy){
    queue<ii> myQ;
    myQ.push({ox, oy});
    dist[ox][oy] = 0;
    Bombs[ox][oy] = true;
    while(!myQ.empty()){
        ii u = myQ.front();
        if (u.f == dx && u.s == dy)
            return dist[dx][dy];
        myQ.pop();
        forn(i, 4){
            int ux = u.f + x[i], uy = u.s + y[i];
            if (isvalid(ux, uy, N, M) && !Bombs[ux][uy]){
                dist[ux][uy] = dist[u.f][u.s] + 1;
                Bombs[ux][uy] = true;
                myQ.push({ux, uy});
            }
        }
    }
    return -1;
}

void solve(){
    int ox, oy, dx, dy;
    while(cin >> N >> M, N || M){
        cin >> Rows;
        memset(Bombs, 0, sizeof(Bombs));
        memset(dist, 0, sizeof(dist));
        //cout << N << ' ' << M << ' ' << Rows << '\n';
        forn(i, Rows){
            cin >> R >> Q;
            //cout << R << ' ' << Q << '\n';
            forn(j, Q){
                cin >> W;
                //cout << W << '\n';
                Bombs[R][W] = true;
            }
        }
        cin >> ox >> oy >> dx >> dy;
        cout << bfs(ox, oy, dx, dy) << '\n';

    }
}

int main(){
    //filIn; //filOut;
    ios_base::sync_with_stdio(false); cin.tie(0);
    solve();

    return 0;
}
