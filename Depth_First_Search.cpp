//Exemplo de dfs usando o exercício URI 1706
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <stack>
#include <list>
#include <limits.h>
#include <string.h>
#include <iomanip>
#include <functional>

using namespace std;

#define pi 3.141592653589793
#define eulerconstant 0.577215664901532
#define sz 500
#define f first
#define s second
#define inf 1000000000
#define inf64 1000000000000000000

typedef pair<int, int> ii;
typedef pair<char, int> ci;
typedef pair<int, string> si;
typedef vector< int > vi;
typedef vector< char > vc;
typedef vector<pair<int, int>> vii;
typedef vector<pair< int, pair<int, int>>> viii;
typedef vector<vector<int>> vvi;
typedef long long ll;

char Let[1050];
bool Visit[sz]; //Vetor de visitados
vi AdjList[sz]; //Lista de adjacêncai

int Bes(int Cur)
{
    Visit[Cur] = true; //Visito o vértice
    int Ans = 0;
    if  (Let[Cur] == 'B')
        Ans = 1;
    for (int to : AdjList[Cur]) //Chamo a função pra cada vértice adjacênte
    {
        if  (!Visit[to])
            Ans += Bes(to);
    }
    return Ans;
}

int main()
{
    int N, M;
    while(scanf("%d %d", &N, &M) != EOF)
    {
        bool Da = true;
        for (int i = 0; i < N; i++) AdjList[i].clear(); //Limpar cada lista
        for (int i = 0; i < N; i++) Visit[i] = 0;		//Atribuir falso a todos vértices

        for (int i = 0; i < N; i++)
            scanf(" %c", &Let[i]); 

        for (int i = 0; i < M; i++)
        {
            int a, b; scanf("%d %d", &a, &b);
            a--;
            b--;
            AdjList[a].push_back(b);	//adiciono Vértices a<->b
            AdjList[b].push_back(a);
        }
        for (int i = 0; i < N; i++)
        {
            if  (!Visit[i])
            {
                int Count = Bes(i); //Chamo a dfs
                if  (Count % 2)
                    Da = false;
            }
        }
        if  (Da)
            printf("Y\n");
        else
            printf("N\n");
    }
}