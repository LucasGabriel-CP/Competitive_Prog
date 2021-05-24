//Dijkstra
//Priority queue com pair
//Pair 		-> Peso / Vértice
//Visitados -> Peso inicial como infinito

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

using namespace std;

#define pi 3.141592653589793
#define eulerconstant 0.577215664901532
#define sz 4050
#define f first
#define s second
#define inf 1000000000
#define inf64 1000000000000000000

typedef pair<int, int> ii;
typedef pair<char, int> ci;
typedef pair<string, int> si;
typedef vector< int > vi;
typedef vector< char > vc;
typedef vector<pair<int, int>> vii;
typedef vector<pair< int, pair<int, int>>> viii;
typedef vector<vector<int>> vvi;
typedef long long ll;

int Visit[sz];
vii AdjList[sz];

int x[] = {0,-1,0,1}, y[] = {-1,0,1,0};

int main()
{
	int N, M;
	priority_queue< ii > myPq;
	
	while (scanf("%d %d", &N, &M) != EOF)
	{
		for	(int i = 0; i < sz; i++) Visit[i] = inf;
		 
		for	(int i = 0; i < M; i++)
		{
			int A, B; scanf("%d %d", &A, &B);		//Adiciona arestas A<->B com peso 1
			AdjList[A].push_back(ii(1, B));
			AdjList[B].push_back(ii(1, A));
		}
		int Com, Fim, E; scanf("%d %d %d", &Com, &Fim, &E);
		
		myPq.push(ii(0, Com));
		Visit[Com] = 0;
		while(!myPq.empty())
		{
			ii Fon = myPq.top();
			myPq.pop();
			for	(int i = 0; i < AdjList[Fon.s].size(); i++)	//Vertices conectados ao "original"
			{
				ii V = AdjList[Fon.s][i]; //Pego um vertice
				if	(V.s != E && Visit[V.s] > Visit[Fon.s] + V.f) //Caso o peso da conexão seja maior que a que eu tô verificando agora
				{
					Visit[V.s] = Visit[Fon.s] + V.f;
					myPq.push(V);	//Adicionar o vértice na fila de prioridade
				}
			}
		}
		printf("%d\n", Visit[Fim]); //Imprimo o peso na posição Fim
		
		for (int i = 0; i < sz; i++) AdjList[i].clear();
	}
}
