#include <bits/stdc++.h>

using namespace std;

const int maxn = 28, inf = 1e9;
vector<int> AdjList[maxn];
stack<int> S;
int tempo[maxn];
bool vis[maxn];

void dfs(int u){
    vis[u] = true;
    for (int v : AdjList[u])
        if (!vis[v]) dfs(v);
    S.push(u);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    string str, num, ver;
    cin.ignore();
    getline(cin, str);
    while(t--){
        int maior=-1;
        while(getline(cin, str), str != "\0"){
            stringstream ss(str);
            ss >> ver;
            ss >> num;
            tempo[ver[0] - 'A'] = stoi(num) * -1;
            maior = max(maior, ver[0] - 'A');
            while(ss >> str){
                for (char c : str){
                    AdjList[ver[0] - 'A'].push_back(c - 'A');
                    maior = max(maior, c - 'A');
                }
            }
        }
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i <= maior; ++i)
            if (!vis[i]) dfs(i);
        vector<int> dist(maior + 1, inf);
        for (; !S.empty(); S.pop()){
            int u = S.top();
            dist[u] = min(dist[u], tempo[u]);
            for (int v : AdjList[u]){
                dist[v] = min(dist[v], dist[u] + tempo[v]);
            }
        }
        int ans = inf;
        for (int i : dist) ans = min(ans, i);
        cout << ans * -1 << '\n';
        if (t) cout << '\n';
        for (int i = 0; i < maxn; ++i) AdjList[i].clear();
    }
}
