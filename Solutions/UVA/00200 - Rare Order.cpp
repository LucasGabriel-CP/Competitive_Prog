#include <bits/stdc++.h>

using namespace std;

#define pi 3.141592653589793
#define eulerconstant 0.577215664901532
#define MAXN 1005
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

unordered_map<char, vc> AdjList;
vector<char> ans;
unordered_set<char> inpt;
int N, vis[MAXN];

void dfs(char u){
    vis[u] = true;
    for (auto v : AdjList[u]){
        if (!vis[v]) dfs(v);
    }
    ans.push_back(u);
}

void TopoSort(){
    memset(vis, 0, MAXN);
    for (auto i : inpt){
        if (!vis[i])
            dfs(i);
    }
    reverse(ans.begin(), ans.end());
}

void solve(){
    string Str, Aux;
    bool ok = false;
    while(cin >> Str){
        if(Str == "#"){
            if (inpt.empty()){
                string::iterator res = unique(Aux.begin(), Aux.end());
                Aux.resize(distance(Aux.begin(), res));
                cout << Aux << '\n';
            }
            else{
                TopoSort();
                for(auto i : ans)
                    cout << i;
                cout << '\n';
            }
            ok = false;
            ans.clear();
            AdjList.clear();
            inpt.clear();

        }
        else{
            if (ok){
                int i = 0,j = 0;
                //cout << Aux << ' ' << Str << '\n';
                while(i < (int)Str.size() && j < (int)Aux.size()){
                    if (Str[i] != Aux[j]){
                        AdjList[Aux[j]].push_back(Str[i]);
                        inpt.insert(Aux[j]);
                        inpt.insert(Str[j]);
                        break;
                    }
                    ++i; ++j;
                }
            }
            Aux = Str;
            ok = true;
        }
    }
}

int main(){
    //filIn; filOut;
    ios_base::sync_with_stdio(false); cin.tie(0);
    solve();
}
