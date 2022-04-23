#include <bits/stdc++.h>

using namespace std;

#define pi 3.141592653589793
#define eps 0.000005
#define eulerconstant 0.577215664901532
#define MAXN 200005
#define LGN 17
#define LSOne(S) ((int)(S) & -(int)(S))
#define f first
#define s second
#define inf ~(1<<31)
#define inf64 1000000000000000000
#define goldenratio ((double)(1 + sqrt(5)) / 2)
#define isvalid(a_, b_, n_, m_) (a_ >= 0 && a_ < n_ && b_ >= 0 && b_ < m_)
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define rforn(i, n) for (int i = (int)(n); i >= 0; --i)
#define forr(i, l, r) for (int i = (int)(l); i < (int)(r); ++i)
#define rforr(i, l, r) for (int i = (int)(l); i >= (int)(r); --i)
#define Mid (l + ((r - l) >> 1))
#define filIn freopen("input.txt", "r", stdin);
#define filOut freopen("output.txt", "w", stdout);

typedef pair<long long, long long> ii;
typedef pair<double, double> dd;
typedef pair<int, pair<int, int>> iii;
typedef pair<char, int> ci;
typedef pair<string, int> si;
typedef pair<int, string> is;
typedef vector< int > vi;
typedef vector< long long > vll;
typedef vector< char > vc;
typedef vector<pair<int, int>> vii;
typedef vector<pair< int, pair<int, int>>> viii;
typedef vector<vector<int>> vvi;
typedef long long ll;
typedef unsigned long long ull;
typedef int no;

bool Vis[35];
int NC;
string N, C;
vi AdjList[35];
unordered_map<string, int> Nodes;

int bfs(int O, int R){
    int Dist[35];
    queue<int> myQ;
    int QntNodes = 0;
    memset(Vis, 0, 35);
    myQ.push(O);
    Dist[O] = 0;
    Vis[O] = true;
    while(!myQ.empty()){
        int v = myQ.front();
        myQ.pop();
        ++QntNodes;
        for (int u : AdjList[v]){
            if (!Vis[u] && Dist[v] + 1 <= R){
                Vis[u] = true;
                Dist[u] = Dist[v] + 1;
                myQ.push(u);
            }
        }
    }
    return QntNodes;
}

void solve(){
    string o;
    int Case = 1, r;
    while(cin >> NC, NC){
        int k = 0;
        forn(i, NC){
            cin >> N >> C;
            if (!Nodes.count(N))
                Nodes[N] = k++;
            if (!Nodes.count(C))
                Nodes[C] = k++;
            AdjList[Nodes[N]].push_back(Nodes[C]);
            AdjList[Nodes[C]].push_back(Nodes[N]);
        }
        cin >> o >> r;
        while(o != "0" || r){
            cout << "Case " << Case++ << ": " << k - (Nodes.count(o) ? bfs(Nodes[o], r) : 0)
            << " nodes not reachable from node " << o << " with TTL = " << r << ".\n";
            cin >> o >> r;
        }
        Nodes.clear();
        forn(i, 35) AdjList[i].clear();
    }
}

int main(){
    //filIn; //filOut;
    ios_base::sync_with_stdio(false); cin.tie(0);
    solve();

    return 0;
}
