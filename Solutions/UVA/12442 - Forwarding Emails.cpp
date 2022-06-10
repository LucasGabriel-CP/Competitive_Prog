#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

const int MAXN = 50005, inf = 1e9;
vector<int> AdjList[MAXN];
bool vis[MAXN], isC[MAXN];
int depth[MAXN], qnt[MAXN], low[MAXN], timer, n;

void dfs(int u, stack<int> &myS){
	vis[u] = true;
	low[u] = qnt[u] = timer++;
	myS.push(u);
	for (int v : AdjList[u]){
		if (qnt[v] == -1){
			dfs(v, myS);
			low[u] = min(low[u], low[v]);
		}
		else if (vis[v])
			low[u] = min(low[u], qnt[v]);
	}
	if (low[u] == qnt[u]){
		 int aux = myS.size() - 1;
		 queue<int> q;
		 for(; !myS.empty() && myS.top() != u; myS.pop()){
			vis[myS.top()] = false;
			q.push(myS.top());
			aux = max(aux, depth[myS.top()]);
		}
		vis[myS.top()] = false;
		if (aux == myS.size() - 1){ myS.pop(); return; }
		isC[myS.top()] = true;
		depth[myS.top()] = aux = max(aux, depth[myS.top()]);
		myS.pop();
		for(; !q.empty(); q.pop()){
			isC[q.front()] = true;
			depth[q.front()] = aux;
		}
	}
}

void dfs(int u){
	vis[u] = true;
	for (int v : AdjList[u]){
		if (!vis[v]){
			dfs(v);
		}
		if (isC[u] && isC[v] && depth[u] == depth[v]) continue;
		depth[u] = max(depth[u], depth[v] + 1);
	}
	if (depth[u] == -1) depth[u] = 0;

}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int t; cin >> t;
	for(int c = 1; c <= t; ++c){
		cin >> n;
		for (int i = 0; i < n; i++){
			AdjList[i].clear();
			qnt[i] = low[i] = depth[i] = -1;
			vis[i] = isC[i] = false;
		}
		for (int i = 0; i < n; i++){
			int a, b; cin >> a >> b;
			--a; --b;
			AdjList[a].push_back(b);
		}
		stack<int> myS;
		for (int i = 0; i < n; ++i){
			if (qnt[i] == -1){
				dfs(i, myS);
			}
		}
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < n; ++i){
			if (!vis[i]){
				dfs(i);
			}
		}
		int where, maior = -1;
		for (int i = 0; i < n; ++i){
			if (depth[i] > maior){
				maior = depth[i];
				where = i + 1;
			}
		}

		cout << "Case " << c << ": " << where << '\n';
	}

	return 0;
}
