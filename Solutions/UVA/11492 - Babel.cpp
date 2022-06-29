#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define inf64 1000000000000000000

typedef pair<string, string> ss;
typedef pair<long long, pair<string, string>> iss;
typedef long long ll;

map<string, vector<ss>> AdjList;
map<string, ll > Dist;
set<string> mySet;

ll Dijkstra(string O, string D){
    priority_queue<iss, vector<iss>, greater<iss>> myPq;
    myPq.push({ 0, {O, " "}});
    Dist[O] = 0;
    while (!myPq.empty()){
        ss Fon = myPq.top().s;
        if (Fon.f == D) break;
        myPq.pop();

        for (int i = 0; i < (int)AdjList[Fon.f].size(); i++){
            string V = AdjList[Fon.f][i].s;
            int W = (int)AdjList[Fon.f][i].f.size();
            string E = AdjList[Fon.f][i].f;
            if (E[0] != Fon.s[0] && Dist[V] > Dist[Fon.f] + W){
                Dist[V] = Dist[Fon.f] + W;
                myPq.push({ Dist[V], {V, E} });
            }
        }
    }

    return Dist[D];
}

int main(){
    int N;
    while (scanf("%d", &N), N){
        char O[100], D[100], I1[100], I2[100], P[100];
        string P1;
        scanf("%s %s", O, D);
        Dist[O] = Dist[D] = inf64;

        for (int i = 0; i < N; i++){
            scanf("%s %s %s", I1, I2, P);
            P1 = P;
            AdjList[I1].push_back({ P, I2 });
            AdjList[I2].push_back({ P, I1 });
            Dist[I1] = inf64;
            Dist[I2] = inf64;
        }
        ll Ans = Dijkstra(D, O);
        if (Ans != inf64)
            printf("%lld\n", Ans);
        else
            printf("impossivel\n");

        AdjList.clear();
        Dist.clear();
        mySet.clear();
    }

    return 0;
}
