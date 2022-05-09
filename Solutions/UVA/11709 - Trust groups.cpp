//DESGRAÇA DE PROBLEMA

#include <bits/stdc++.h>

using namespace std;

#define pi 3.141592653589793
#define eulerconstant 0.577215664901532
#define MAXN 1005
#define LGN 15
#define LSOne(S) ((int)(S) & -(int)(S))
#define f first
#define s second
#define inf (int)1e9
#define inf64 (int)4e18
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
typedef unsigned long long ll;
typedef int no;

int ans, n, m, low[MAXN], qnt[MAXN], dfsTime;
vi AdjList[MAXN];
bool vis[MAXN];

void dfs(int u, stack<int> &myS){
    low[u] = qnt[u] = dfsTime++;
    myS.push(u);
    vis[u] = true;
    for (auto v : AdjList[u]){
        if(qnt[v] == -1){
            dfs(v, myS);
            low[u] = min(low[v], low[u]);
        }
        else if(vis[v])
            low[u] = min(qnt[v], low[u]);
    }
    if (low[u] == qnt[u]){
        for(; !myS.empty() && myS.top() != u; myS.pop()){
            vis[myS.top()] = false;
        }
        vis[myS.top()] = false;
        myS.pop();
        ++ans;
    }
}

void solve(){
    unordered_map<string, int> myHash;
    int id = 0;
    forn(i, MAXN){
        low[i] = vis[i] = 0;
        qnt[i] = -1;
        AdjList[i].clear();
    }
    forn(i, n){
        string Nome; getline(cin, Nome);
        myHash[Nome] = id++;
    }
    string a, b;
    while(m--){
        getline(cin, a);
        getline(cin, b);
        AdjList[myHash[a]].push_back(myHash[b]);
    }
    stack<int> myS;
    ans = dfsTime = 0;
    forn(i, n)
        if(qnt[i] == -1)
            dfs(i, myS);

    cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//filIn;	//filOut;
    while(cin >> n >> m, n || m){
        cin.ignore();
        solve();
    }

	return 0;
}
