#include <bits/stdc++.h>
#define f first
#define s second
#define isvalid(a_, b_, n_, m_) (a_ >= 0 && a_ < n_ && b_ >= 0 && b_ < m_)
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define rforn(i, n) for (int i = (int)(n); i >= 0; --i)
#define forr(i, l, r) for (int i = (int)(l); i < (int)(r); ++i)
#define rforr(i, l, r) for (int i = (int)(l); i >= (int)(r); --i)

using namespace std;

const int MAXN = 105, inf = 1e9;
int n = 8, m = 8;
int xK[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, yK[8] = {-1, 0, 1, 1, -1, -1, 0, 1};
int dist[MAXN][MAXN];
int r1, c1, r2, c2, r3, c3;

void bfs(int ox, int oy, int dx, int dy){
    forn(i, n)
        forn(j, m)
            dist[i][j] = -1;
    dist[ox][oy] = 0;
    queue<pair<int, int>> q;
    q.push({ox, oy});
    while(!q.empty()){
        int x = q.front().f, y = q.front().s;
        if (x == dx && dy == y)
            return;
        q.pop();
        forn(i, 8){
            int ui = x + xK[i], uj = y + yK[i];
            if (isvalid(ui, uj, n, m) && dist[ui][uj] == -1 && (ui != r3 || uj != c3)){
                    dist[ui][uj] = dist[x][y] + 1;
                    q.push({ui, uj});
                }
        }
    }
}

void solve(){
    --r3; --c3; --r2; --c2; --r1; --c1;
    bfs(r1, c1, r2, c2);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int c = 1;
	while(cin >> r1 >> c1 >> r2 >> c2 >> r3 >> c3){
        solve();
        cout << "Case " << c++ << ": " << dist[r2][c2] << '\n';
	}
	return 0;
}
