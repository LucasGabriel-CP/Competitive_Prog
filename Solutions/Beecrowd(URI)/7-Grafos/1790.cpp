#include <bits/stdc++.h>

using namespace std;

typedef vector< int > vi;

int N, M, Timer, Ans;
vector<bool> Visit;
vi AdjList[1050], tin, low;
map<int, int> Bridge;

void DFS(int v, int p = -1)
{
    Visit[v] = true;
    tin[v] = low[v] = Timer++;
    for (int to : AdjList[v])
    {
        if (to == p)	continue;
        if (Visit[to])
            low[v] = min(low[v], tin[to]);
        else
        {
            DFS(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                Ans++;
        }
    }
}

void FindBridge()
{
    Ans = 0;
    Timer = 0;
    Visit.assign(N, false);
    tin.assign(N, -1);
    low.assign(N, -1);

    for (int i = 0; i < N; i++)
    {
        if (!Visit[i])
        {
            DFS(i);
        }
    }

    cout << Ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    while (cin >> N >> M)
    {
        while (M--)
        {
            int u, v;
            cin >> u >> v;
            AdjList[u - 1].push_back(v - 1);
            AdjList[v - 1].push_back(u - 1);
        }
        FindBridge();
        for (int i = 0; i < N; i++) AdjList[i].clear();
        Bridge.clear();
    }

    return 0;
}