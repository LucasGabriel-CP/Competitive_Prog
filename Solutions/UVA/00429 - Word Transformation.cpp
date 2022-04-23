#include <bits/stdc++.h>

using namespace std;

#define pi 3.141592653589793
#define eps 0.000005
#define eulerconstant 0.577215664901532
#define MAXN 10005
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

vvi ListAdj;

int bfs(int o, int d, int N){
    queue<int> myQ;
    bool Vis[N];
    int Dist[N];
    forn(i, N){
        Vis[i] = Dist[i] = 0;
    }
    myQ.push(o);
    while(!myQ.empty()){
        int u = myQ.front();
        if (u == d) return Dist[u];
        myQ.pop();
        for(int v : ListAdj[u]){
            if (!Vis[v]){
                Vis[v] = true;
                Dist[v] = Dist[u] + 1;
                myQ.push(v);
            }
        }
    }
    return 0;
}

void solve(){
    int t; cin >> t;
    string Str;
    getline(cin, Str);
    cin.ignore();
    forn(z, t){
        if (z) cout << '\n';
        unordered_map<string, int> myMap;
        vector<string> Vet[11];
        int id = 0;
        while(getline(cin, Str) && Str != "*"){
            myMap[Str] = id++;
            Vet[(int)Str.size()].push_back(Str);
        }
        ListAdj.assign(id, vi());
        forn(c, 11){
            forn(i, (int)Vet[c].size()){
                forr(j, i + 1, (int)Vet[c].size()){
                    int Count = 0;
                    for (int k = 0; k < c && Count <= 1; ++k)
                        if (Vet[c][i][k] != Vet[c][j][k]) ++Count;
                    if (Count <= 1){
                        int v = myMap[Vet[c][i]], e = myMap[Vet[c][j]];
                        ListAdj[v].push_back(e);
                        ListAdj[e].push_back(v);
                    }
                }
            }
        }
        while(getline(cin, Str) && Str != "\0"){
            string a = "", b = "";
            for(int i = 0; i < Str.size() && Str[i] != ' '; a += Str[i], i++);
            for(int i = a.size() + 1; i < Str.size() && Str[i] != ' '; b += Str[i], i++);
            cout << Str << ' ' << (a.size() != b.size() ? 0 : bfs(myMap[a], myMap[b], id)) << '\n';
        }
    }
}

int main(){
    //filIn; //filOut;
    ios_base::sync_with_stdio(false); cin.tie(0);
    solve();

    return 0;
}
