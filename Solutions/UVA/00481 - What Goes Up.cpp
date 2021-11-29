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

vi Vet, P;

void RecLis(int end){
    stack<int> Pilha;
    for(; P[end] >= 0; end = P[end])
        Pilha.push(Vet[end]);
    cout << Vet[end] << '\n';
    for(; !Pilha.empty(); Pilha.pop())
        cout << Pilha.top() << '\n';
}

void solve(){
    int N = (int)Vet.size();
    vi dp(N + 1, 0), Lid(N + 1);
    P.assign(N + 1, 0);
    int lis = 0, lisEnd = 0;
    for (int i = 0; i < N; ++i){
        int pos = lower_bound(dp.begin(), dp.begin() + lis, Vet[i]) - dp.begin();
        dp[pos] = Vet[i];
        Lid[pos] = i;
        P[i] = pos ? Lid[pos - 1] : -1;
        if (pos + 1 > lis) {
            lis = pos + 1;
            lisEnd = i;
        }
    }
    cout << lis << '\n' << "-\n";
    RecLis(lisEnd);
}

int main(){
//    filIn; filOut;
    int v;
    while(cin >> v){
        Vet.push_back(v);
    }
    solve();

    return 0;
}
