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
#define sz 500
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
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	priority_queue< ii > myPq;
	int C; scanf("%d", &C);
    for (int i = 0; i < C; i++)
    {
        int Ans, N, M, E, T; scanf("%d %d %d %d", &N, &E, &T, &M);		 
		for	(int j = 0; j < M; j++)
		{
			int A, B, P; scanf("%d %d %d", &A, &B, &P);		//Adiciona arestas A->B com peso P
			A--;
			B--;
			AdjList[A].push_back(ii(P, B));
		}
		E--;
		Ans = 0;
		for (int j = 0; j < N; j++)
		{
			for	(int k = 0; k < sz; k++) Visit[k] = inf;
			myPq.push(ii(0, j));
			Visit[j] = 0;
			while(!myPq.empty())
			{
				ii Fon = myPq.top();
				myPq.pop();
				for	(int k = 0; k < AdjList[Fon.s].size(); k++)	//Vertices conectados ao "original"
				{
					ii V = AdjList[Fon.s][k]; //Pego um vertice
					if	(Visit[V.s] > Visit[Fon.s] + V.f) //Caso o peso da conexão seja maior que a que eu tô verificando agora
					{
						Visit[V.s] = Visit[Fon.s] + V.f;
						myPq.push(V);	//Adicionar o vértice na fila de prioridade
					}
				}
			}
			if (Visit[E] <= T)
				Ans++;
		}
        printf("%d\n", Ans);
		if (i < C - 1)
			printf("\n");
		for (int k = 0; k < sz; k++) AdjList[k].clear();
    }
}