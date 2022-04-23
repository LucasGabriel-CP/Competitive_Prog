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

vc AdjList[MAXN];
vector<string> ans;
unordered_map<char, int> myMap;
unordered_map<int,char> myMap2;
int N, in_depth[MAXN];

void TopoSort(string &Str, bool Vis[]){
    bool ok = false;
    forn(i, N){
        if (!in_depth[i] && !Vis[i]){
            for (char u : AdjList[i]){
                --in_depth[myMap[u]];
            }
            Vis[i] = true;
            Str.push_back(myMap2[i]);
            TopoSort(Str, Vis);

            Vis[i] = false;
            Str.pop_back();
            for (char u : AdjList[i]){
                ++in_depth[myMap[u]];
            }
            ok = true;
        }
    }
    if (!ok && Str.size()){
        ans.push_back(string(Str.rbegin(), Str.rend()));
    }
}

void solve(){
    int c; cin >> c;
    string Str, aux, Tot;
    getline(cin, Str);
    cin.ignore();
    while(c--){
        getline(cin, Str);
        N = 0;
        aux = Tot = "";
        for (auto i : Str){
            if (i != ' '){
                aux += i;
            }
            else{
                myMap2[N] = aux[0];
                myMap[aux[0]] = N++;
                aux = "";
            }
        }
        if (aux != ""){
            myMap2[N] = aux[0];
            myMap[aux[0]] = N++;
        }
        getline(cin, Str);

        memset(in_depth, 0, MAXN);
        for (int i = 0; i < (int)Str.size(); i += 4){
            AdjList[myMap[Str[i + 2]]].push_back(Str[i]);
            ++in_depth[myMap[Str[i]]];
        }
        aux = "";
        bool vis[N + 5];
        memset(vis, 0, N + 5);

        TopoSort(aux, vis);
        if (ans.empty())
            cout << "NO\n";
        else{
            sort(ans.begin(), ans.end());
            for(auto i : ans){
                forn(j, (int)i.size()-1)
                    cout << i[j] << ' ';
                cout << i.back() << '\n';
            }
        }
        if (c) cout << '\n';
        ans.clear();
        myMap.clear();
        forn(i, MAXN) AdjList[i].clear();
        getline(cin, Str);
    }
}

int main(){
    //filIn; filOut;
    ios_base::sync_with_stdio(false); cin.tie(0);
    solve();
}
