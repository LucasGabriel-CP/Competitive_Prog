#include <iostream>
#include <vector>
#include <unordered_map>

const int MAXN = 1e4;

std::unordered_map<int, char> Arestas[MAXN];
std::vector<int> AdjList[MAXN];
char Cor[MAXN];
int tempoIni[MAXN], tempoFim[MAXN], tempoDfs;

void dfs(int u){
    Cor[u] = 'g';
    tempoIni[u] = tempoDfs++;
    for (int v : AdjList[u]){
        if (Cor[v] == 'w'){
            Arestas[u][v] = 'T';
            dfs(v);
        }
        else if (Cor[v] == 'g')
            Arestas[u][v] = 'B';
        else{
            if (tempoIni[u] > tempoFim[v])
                Arestas[u][v] = 'C';
            else
                Arestas[u][v] = 'F';
        }
    }
    tempoFim[u] = tempoDfs++;
    Cor[u] = 'b';
}

int main(){
    int n;
    while(std::cin >> n, n){
        for(int i = 1; i <= n; ++i){
            Cor[i] = 'w';
            AdjList[i].clear();
            Arestas[i].clear();
        }
        for (int i = 0; i < n; ++i){
            int a, b;
            std::cin >> a >> b;
            AdjList[a].push_back(b);
        }
    }
}
