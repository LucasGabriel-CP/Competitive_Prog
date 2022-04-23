#include <bits/stdc++.h>

using namespace std;

#define pi 3.1415926535897
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
typedef pair<ll, pair<ll, int>> no;

int t, N, Q, Vet[MAXN];
ll Lazy[4 * MAXN];
no Seg[4 * MAXN];

void modify(no &t, no a, no b, int l, int r){
    t.s.s = a.s.s + b.s.s;
    t.f = a.f + a.s.s * (b.s.f) + b.f;
    t.s.f = a.s.f + b.s.f;
}

void Give(int l, int r, ll la, no& t){
    t.f += la * ((t.s.s + 1) * (t.s.s / 2.0));
    t.s.f += la * (t.s.s);
}

void prop(int id, int l, int r){
    if (Lazy[id]){
        Give(l, r, Lazy[id], Seg[id]);
        if (l != r){
            Lazy[2*id] += Lazy[id];
            Lazy[2*id + 1] += Lazy[id];
        }
        Lazy[id] = 0;
    }
}

void build(int l = 0, int r = N - 1, int id = 1){
    Lazy[id] = 0;
    if (r == l){
        Seg[id] = {100, {100, 1}};
        return;
    }
    build(l, Mid, 2 * id);
    build(Mid + 1, r, 2 * id + 1);
    modify(Seg[id], Seg[2 * id], Seg[2 * id + 1], l, r);
}

void upd(int i, int j, int x, int l = 0, int r = N - 1, int id = 1){
    if (i <= l && r <= j){
        Lazy[id] += (ll)x;
        prop(id, l, r);
        return;
    }
    prop(id, l, r);
    if (r < i || j < l) return;
    upd(i, j, x, l, Mid, 2 * id);
    upd(i, j, x, Mid + 1, r, 2 * id + 1);
    modify(Seg[id], Seg[2 * id], Seg[2 * id + 1], l, r);

}

no query(int i, int j, int l = 0, int r = N - 1, int id = 1){
    if (r < i || j < l) return {0, {0, 0}};
    prop(id, l, r);
    if (i <= l && r <= j) return Seg[id];
    no Op1 = query(i, j, l, Mid, 2 * id);
    no Op2 = query(i, j, Mid + 1, r, 2 * id + 1);
    no ans; modify(ans, Op1, Op2, l, r);
    return ans;
}

void solve(){
    cin >> t;
    string Str;
    int a, b, x;
    forn(c, t){
        cin >> N >> Q;
        build();
        cout << "Case " << c + 1 << ":\n";
        while(Q--){
            cin >> Str;
            if (Str == "query"){
                cin >> a >> b;
                if (a > b) swap(a, b);
                no ans;
                ans = query(a - 1, b - 1);
                cout << ans.f << '\n';
            }
            else{
                cin >> a >> b >> x;
                upd(a - 1, b - 1, x);
            }
        }
    }
}

int main(){
//    filIn; filOut;
    ios_base::sync_with_stdio(false); cin.tie(0);
    solve();

    return 0;
}
