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
int n, m;
int xK[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, yK[8] = {-1, 0, 1, 1, -1, -1, 0, 1};
int xH[8] = {2, 2, 1, 1, -1, -1, -2, -2}, yH[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
char Matrix[MAXN][MAXN];
int dist[MAXN][MAXN];

void bfs(int ox, int oy, int dx, int dy){
    forn(i, n)
        forn(j, m)
            dist[i][j] = -1;
    dist[ox][oy] = 0;
    queue<pair<int, int>> q;
    q.push({ox, oy});
    while(!q.empty()){
        int x = q.front().f, y = q.front().s;
        if (Matrix[x][y] == 'B') return;
        q.pop();
        forn(i, 8){
            int ui = x + xK[i], uj = y + yK[i];
            if (isvalid(ui, uj, n, m) && dist[ui][uj] == -1
                && (Matrix[ui][uj] == '.' || Matrix[ui][uj] == 'B')){
                    dist[ui][uj] = dist[x][y] + 1;
                    q.push({ui, uj});
                }
        }
    }
}

void solve(){
    int x, y, dx, dy;
    cin >> n >> m;
    forn(i, n)
        forn(j, m){
            cin >> Matrix[i][j];
            if (Matrix[i][j] == 'A'){
                x = i; y = j;
            }else if (Matrix[i][j] == 'B'){
                dx = i; dy = j;
            }
        }
    if (abs(x - dx) <= 1 && abs(y - dy) <= 1){
        cout << "Minimal possible length of a trip is 1\n";
        return;
    }
    forn(i, n)
        forn(j, m){
            if (Matrix[i][j] == 'Z'){
                forn(k, 8){
                    int ui = i + xH[k], uj = j + yH[k];
                    if (isvalid(ui, uj, n, m)){
                        if (Matrix[ui][uj] == '.')
                            Matrix[ui][uj] = 'X';
                    }
                }
            }
        }
    bfs(x, y, dx, dy);
    if (dist[dx][dy] != -1){
        cout << "Minimal possible length of a trip is " << dist[dx][dy] << '\n';
    }
    else
        cout << "King Peter, you can't go now!\n";
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int t;
	cin >> t;
	while(t--)
        solve();
	return 0;
}
