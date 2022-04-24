#include <bits/stdc++.h>

using namespace std;

#define pi 3.141592653589793
#define eulerconstant 0.577215664901532
#define MAXN 100005
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

int n, Vet[105];

void solve(){
    string aux, Str; getline(cin, Str);
    stringstream ss(Str);
    int id = 0;
    while(ss >> aux){
        Vet[id++] = stoi(aux);
    }
    int Maior = -1;
    forn(i, id){
        forr(j, i + 1, id){
            Maior = max(__gcd(Vet[i], Vet[j]), Maior);
        }
    }
    cout << Maior << '\n';
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//filIn; //filOut;
	int Case; cin >> Case;
	cin.ignore();
	forn(i, Case){
        solve();
	}

	return 0;
}
