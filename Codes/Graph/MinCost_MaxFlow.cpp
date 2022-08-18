#include <bits/stdc++.h>

using namespace std;

const int MAXN = 305;
const long long inf64 = (long long)1e18;
typedef long long ll;

struct edge{
    int from, to;
    ll cap, cost;
    edge(){}
    edge(int f, int t, ll cap_, ll c){ from = f; to = t; cap = cap_; cost = c; }
};

vector<int> adj[MAXN];
vector<edge> edges;
bool inq[MAXN];
int p[MAXN];
ll d[MAXN];

bool sssp(int source, int sink){
    for (int i = 0; i < MAXN; i++) d[i] = inf64;
    memset(p, -1, sizeof(p));
    memset(inq, 0, sizeof(inq));
    queue<int> q;
    q.push(source);
    d[source] = 0;
    while (!q.empty()){
        int u = q.front();
        inq[u] = false;
        q.pop();
        for (int v: adj[u]){
            edge e = edges[v];
            if (e.cap > 0 && d[e.to] > d[u] + e.cost){
                d[e.to] = d[u] + e.cost;
                p[e.to] = v;
                if (!inq[e.to]){
                    inq[e.to] = true;
                    q.push(e.to);
                }
            }
        }
    }
    return d[sink] != inf64;
}

void add(int from, int to, int c, ll custo){
    edges.emplace_back(from, to, c, custo);
    edges.emplace_back(to, from, 0, -custo);
    //represent back edge as the next idx
    adj[from].push_back(edges.size()-2);
    adj[to].push_back(edges.size()-1);
}

//O((N^2)(M^2)) with bellmanford/spaf
//O((N^3)M) with dijkstra
ll minCost(int n, ll k, int source, int sink){
    ll flow = 0, custo = 0;
    while(flow < k && sssp(source, sink)){
        ll f = inf64;
        int cur = p[sink];
        while(cur != -1){
            f = min(f, edges[cur].cap);
            cur = p[edges[cur].from];
        }
        cur = p[sink];
        while(cur != -1){
            edge &going = edges[cur];
            edge &turn = edges[cur^1];
            going.cap -= f;
            turn.cap += f;
            cur = p[going.from];
        }
        flow  += f;
        custo += f*d[sink];
    }
    if (flow < k) return -1;
    else return custo;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    while (cin >> n >> m){
        vector<edge> vet;
        for(int i = 0; i < MAXN; i++) adj[i].clear();
        edges.clear();
        for(int i = 0; i < m; i++){
            //Read the edges
        }
        int d, k; cin >> d >> k; //All edges with capacity 'k'
		int source = 0, sink = 2*n+1; //create source to conect initial point and sink final
		for (edge e: vet){
            add(e.from, e.to, k, e.cost);
            add(e.to, e.from, k, e.cost); //undirected graph
		}
		//Need flow to be at least 'd'
        add(source, 1, d, 0);
        add(n, sink, d, 0);
        ll ans = minCost(n, d, source, sink);
        if (ans == -1) cout << "impossivel\n\n";
        else cout << ans << "\n\n";
    }

	return 0;
}
