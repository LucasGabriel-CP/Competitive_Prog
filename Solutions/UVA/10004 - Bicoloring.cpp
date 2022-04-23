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

vi AdjList[MAXN];
int side[MAXN];
int N, l;

bool isBi(){
    bool ok = true;
    forn(i, N) side[i] = -1;
    queue<int> myQ;
    myQ.push(0);
    side[0] = 0;
    while(!myQ.empty()){
        int v = myQ.front();
        myQ.pop();
        for(auto i : AdjList[v]){
            if (side[i] == -1){
                side[i] = side[v] ^ 1;
                myQ.push(i);
            }
            else
                ok &= (side[v] != side[i]);
        }
    }
    return ok;
}

void solve(){
    while(cin >> N, N){
        cin >> l;
        forn(i, N) AdjList[i].clear();
        forn(i, l){
            int a, b; cin >> a >> b;
            AdjList[a].push_back(b);
            AdjList[b].push_back(a);
        }
        cout << (isBi() ? "BICOLORABLE" : "NOT BICOLORABLE") << ".\n";
        //forn(i, l) cout << side[i] <<'\n';
    }
}

int main(){
    //filIn; filOut;
    ios_base::sync_with_stdio(false); cin.tie(0);
    solve();
}
