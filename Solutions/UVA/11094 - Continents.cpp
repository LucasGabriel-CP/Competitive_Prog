#include <bits/stdc++.h>

using namespace std;

#define pi 3.141592653589793
#define eulerconstant 0.577215664901532
#define MAXN 100005
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

char Matrix[21][21], land;
bool vis[21][21];
int n, m, x[8] = {1, -1, 0, 0, -1, 1, 1, -1}, y[8] = {0, 0, 1, -1, 1, 1, -1, -1};


int bfs(int vx, int vy){
	queue<ii> myQ;
	int ans = 0;
	myQ.push({vx, vy});
	vis[vx][vy] = true;
	while(!myQ.empty()){
		ii u = myQ.front();
		vis[u.f][u.s] = true;
		++ans;
		myQ.pop();
		forn(i, 4){
			int tox = u.f + x[i], toy = u.s + y[i];
			if (tox == n || tox == -1) continue;
			if (toy == -1){
				toy = m - 1;
			}
			else if (toy == m){
				toy = 0;
			}
			if (!vis[tox][toy] && Matrix[tox][toy] == land){
				myQ.push({tox, toy}); vis[tox][toy] = true;
			}
		}
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//filIn; filOut;
	while(cin >> n >> m){
		memset(vis, 0, sizeof(vis));
		forn(i, n) cin >> Matrix[i];
		int ox, oy; cin >> ox >> oy;
		land = Matrix[ox][oy];
		bfs(ox, oy);
		int ans = 0;
		forn(i, n){
			forn(j, m){
				if (!vis[i][j] && Matrix[i][j] == land){
					ans = max(ans, bfs(i, j));
				}
			}
		}
		cout << ans << '\n';
	}


	return 0;
}
