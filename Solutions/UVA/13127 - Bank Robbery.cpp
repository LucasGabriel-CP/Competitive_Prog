#include <bits/stdc++.h>
#define f first
#define s second
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define rforn(i, n) for (int i = (int)(n); i >= 0; --i)
#define forr(i, l, r) for (int i = (int)(l); i < (int)(r); ++i)
#define rforr(i, l, r) for (int i = (int)(l); i >= (int)(r); --i)

using namespace std;

const int MAXN = 1005, inf = 1e9;
vector<pair<int, int>> AdjList[MAXN];
int banks[MAXN], police[MAXN], dist[MAXN];

int Dijkstra(int p, int b){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> myPq;
    forn(i, p){
        myPq.push({0, police[i]});
        dist[police[i]] = 0;
    }
    while(!myPq.empty()){
        int d = myPq.top().f;
        int u = myPq.top().s;
        myPq.pop();
        for (auto v : AdjList[u]){
            int to = v.f, w = v.s;
            if (dist[to] > dist[u] + w){
                dist[to] = dist[u] + w;
                myPq.push({dist[to], to});
            }
        }
    }
    int ans = -1;
    forn(i, b){
        ans = max(ans, dist[banks[i]]);
    }
    return ans;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, m, b, p;
	while(cin >> n >> m >> b >> p){
        forn(i, n){ dist[i] = inf; AdjList[i].clear(); }
        forn(i, m){
            int a, b, p; cin >> a >> b >> p;
            AdjList[a].push_back({b, p});
            AdjList[b].push_back({a, p});
        }
        forn(i, b) cin >> banks[i];
        forn(i, p) cin >> police[i];
        int maior = Dijkstra(p, b);
        vector<int> ans;
        forn(i, b){
            if (dist[banks[i]] == maior) ans.push_back(banks[i]);
        }
        cout << (int)ans.size() << ' ';
        if (maior == inf) cout << "*\n";
        else cout << maior << '\n';
        sort(ans.begin(), ans.end());
        cout << ans[0];
        forr(i, 1, (int)ans.size()) cout << ' ' << ans[i];
        cout << '\n';
	}

	return 0;
}
