#include <bits/stdc++.h>

using namespace std;

#define pi 3.1415926535897
#define eulerconstant 0.577215664901532
#define MAXN 300000
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

int N, M;
char Matrix[105][105];
bool vis[105][105];
int x[4] = {0, 0, 1, -1}, y[4] = {1, -1, 0, 0};

int bfs(int i, int j){
    int Ans = 0;
    queue<ii> myQ;
    myQ.push({i, j});
    vis[i][j] = true;
    while(!myQ.empty()){
        ii v = myQ.front();
        myQ.pop();
        if (Matrix[v.f][v.s] == 'G') Ans++;
        bool safe = true;
        forn(k, 4){
            ii u = {v.f + x[k], v.s + y[k]};
            if (isvalid(u.f, u.s, N, M) && Matrix[u.f][u.s] == 'T'){
                safe = false;
                break;
            }
        }
        if (!safe) continue;
        forn(k, 4){
            ii u = {v.f + x[k], v.s + y[k]};
            if (isvalid(u.f, u.s, N, M) && !vis[u.f][u.s] && Matrix[u.f][u.s] != '#'){
                myQ.push(u);
                vis[u.f][u.s] = true;
            }
        }
    }
    return Ans;
}

void solve(){
    int t = 0;
    while(scanf("%d %d", &M, &N) != EOF){
        int oi, oj;
        forn(i, N){
            forn(j, M){
                scanf(" %c", &Matrix[i][j]);
                if (Matrix[i][j] == 'P'){
                    oi = i; oj = j;
                }
            }
        }
        memset(vis, 0, sizeof(vis));
        printf("%d\n", bfs(oi, oj));
    }
}

int main(){
    //filIn; //filOut;
    //ios_base::sync_with_stdio(false); cin.tie(0);
    solve();

    return 0;
}
