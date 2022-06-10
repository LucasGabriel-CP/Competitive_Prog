#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

const int MAXN = 350;

int n, m;
vi AdjList[MAXN];

bool check(){
    vector<int> side(n, -1);
    bool ok = true;
    queue<int> q;
    for (int i = 0; i < n; ++i){
        if (side[i] == -1){
            q.push(i);
            side[i] = 0;
            while(!q.empty()){
                int v = q.front();
                q.pop();
                for (int u : AdjList[v]){
                    if (side[u] == -1){
                        side[u] = side[v] ^ 1;
                        q.push(u);
                    }
                    else ok &= side[u] != side[v];
                }
            }
        }
    }
    return ok;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> n, n){
        for (int i = 0; i < n; ++i) AdjList[i].clear();
        int a, b;
        while(cin >> a >> b, a && b){
            AdjList[a-1].push_back(b-1);
            AdjList[b-1].push_back(a-1);
        }
        cout << (check() ? "YES\n" : "NO\n");
    }

	return 0;
}
