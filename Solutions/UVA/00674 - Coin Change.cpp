#include <bits/stdc++.h>

using namespace std;

#define pi 3.141592653589793
#define eulerconstant 0.577215664901532
#define MAX_N 100000
#define MAXLOGN 10
#define f first
#define s second
#define inf ~(1<<31)
#define inf64 1000000000000000000
#define goldenratio ((double)(1 + sqrt(5)) / 2)
#define isvalid(a_, b_, n_, m_) (a_ >= 0 && a_ < n_ && b_ >= 0 && b_ < m_)
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define forr(i, l, r) for (int i = (int)(l); i < (int)(r); ++i)
#define Mid ((l + r) >> 1)
#define filIn freopen("input.txt", "r", stdin);
#define filOut freopen("output.txt", "w", stdout);

typedef pair<int, int> ii;
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
typedef vector<vector<long long>> vvll;
typedef long long ll;
typedef int no;

int N = 5, C = 7490, Vet[5] = {1, 5, 10, 25, 50};
int dp[5][7500];

void solve(){
    forn(i, N) dp[i][0] = 1;
    for (int i = 0; i < N; ++i){
        for (int j = 1; j <= C; ++j){
            if (Vet[i] > j) dp[i][j] = i ? dp[i - 1][j]  : 0;
            else dp[i][j] = dp[i][j - Vet[i]] + (i ? dp[i - 1][j] : 0);
        }
    }
}

int main(){
    solve();
    int T;
    while(cin >> T){
        cout << dp[N - 1][T] << '\n';
    }
    return 0;
}
