#include <bits/stdc++.h>

using namespace std;

#define MAXN 100005
#define LGN 17

struct FlowEdge{
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, int cap) : v(v), u(u), cap(cap){}
};


struct Dinic{
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> Adj;
    vector<int> level, ptr;
    queue<int> myQ;
    int n, s, t, m = 0;


    Dinic(int n, int s, int t) : n(n), s(s), t(t){
        Adj.resize(n); level.resize(n); ptr.resize(n);
    }

    void add_edge(int v, int u, long long cap){
        edges.emplace_back(v, u, cap); edges.emplace_back(u, v, 0);
        Adj[v].push_back(m); Adj[u].push_back(m + 1); m += 2;
    }

    bool bfs(){
        while(!myQ.empty()){
            int v = myQ.front();
            myQ.pop();
            for (int id : Adj[v]){
                if (edges[id].cap - edges[id].flow < 1) continue;
                if (level[edges[id].u] != -1) continue;
                level[edges[id].u] = level[id] + 1;
                myQ.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed){
        if (!pushed) return 0;
        if (v == t) return pushed;
        for (int& cid = ptr[v]; cid < (int)Adj[v].size(); ++cid){
            int id = Adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap -edges[id].flow < 1) continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (!tr) continue;
            edges[id].flow = tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long flow(){
        long long f = 0;
        while(true){
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            if (!bfs()) return f;
            fill(ptr.begin(), ptr.end(), 0);
            while(long long pushed = dfs(s, flow_inf)) f += pushed;
        }
        return f;
    }
};
