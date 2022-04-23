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

int n, m, low[MAXN], qnt[MAXN], dfsTime;
vi AdjList[MAXN];
bool vis[MAXN];
unordered_map<string, int> myHashIn;
unordered_map<int, string> myHashOut;

void tarjs(int u, stack<int> &myS){
    low[u] = qnt[u] = dfsTime++;
    myS.push(u);
    vis[u] = true;
    for(auto v : AdjList[u]){
        if (qnt[v] == -1){
            tarjs(v, myS);
            low[u] = min(low[u], low[v]);
        }
        else if (vis[v]){
            low[u] = min(low[u], low[v]);
        }
    }
    if (low[u] == qnt[u]){
        for(; !myS.empty() && myS.top() != u; myS.pop()){
            cout << myHashOut[myS.top()] << ", ";
            vis[myS.top()] = false;
        }
        vis[myS.top()] = false;
        cout << myHashOut[myS.top()] << '\n'; myS.pop();
    }
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//filIn; //filOut;
	int Count = 0;
	while(cin >> n >> m, n || m){
        if (Count) cout << '\n';
        forn(i, n + 1){
            AdjList[i].clear();
            low[i] = vis[i] = 0;
            qnt[i] = -1;
        }
        myHashIn.clear();
        myHashOut.clear();
        stack<int> myS;
        int k = 0;
        string a, b;
        forn(i, m){
            cin >> a >> b;
            if (!myHashIn.count(a)){ myHashOut[k] = a; myHashIn[a] = k++; }
            if (!myHashIn.count(b)){ myHashOut[k] = b; myHashIn[b] = k++; }
            AdjList[myHashIn[a]].push_back(myHashIn[b]);
        }
        dfsTime = 0;
        cout << "Calling circles for data set " << ++Count << ":\n";
        forn(i, n){
            if (qnt[i] == -1){
                tarjs(i, myS);
            }
        }
	}

	return 0;
}
