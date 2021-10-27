#include <cstdio>
#include <iostream>
#include <map>
#include <string>

using namespace std;

#define sz 350

typedef vector< int > vi;

bool Visit[sz];
vi AdjList[sz];

int x[] = {0,-1,0,1}, y[] = {-1,0,1,0};

void dfs(int at)
{
	
	Visit[at] = 1;
	for	(int to : AdjList[at])
	{
		if	(!Visit[to])
			dfs(to);
	}

}

int main ()
{
	int Cont = 0, M, N;
	string Aux, V1, V2;
	map< string, int > myMap;
	
	for	(int i = 0; i < sz; i++) Visit[i] = 0;
	
	scanf("%d %d", &M, &N);	
	for	(int i = 0; i < N; i++)
	{
		cin >> V1 >> Aux >> V2;
		if	(!myMap.count(V1))
		{
			myMap[V1] = Cont;
			Cont++;
		}
		if	(!myMap.count(V2))
		{
			myMap[V2] = Cont;
			Cont++;
		}
		AdjList[myMap[V1]].push_back(myMap[V2]);
		AdjList[myMap[V2]].push_back(myMap[V1]);
	}
	
	int Count = 0;
	for	(int i = 0; i < M; i++)
	{
		if	(!Visit[i])
		{
			Count++;
			dfs(i);
		}
	}
	printf("%d\n", Count);
}