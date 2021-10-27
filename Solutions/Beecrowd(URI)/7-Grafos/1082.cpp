#include<bits/stdc++.h>

using namespace std;

typedef vector< int > vi;
bool Visit[676];
vi AdjList[26];
vi Cesto;

int j, Ver, x[] = { 0,-1,0,1 }, y[] = { -1,0,1,0 };

void dfs(int at)
{
	Cesto.push_back(at);

	Visit[at] = 1;

	for (int to : AdjList[at])
	{
		if (!Visit[to])
			dfs(to);
	}
}

int main()
{
	int Aux, Count, E, N;
	char Ar1, Ar2, Cara;
	map< char, int > myMapi;
	map< int, char > myMapc;
	for (Aux = 0, Cara = 'a'; Aux < 26; Aux++, Cara++)
	{
		myMapi[Cara] = Aux;
		myMapc[Aux] = Cara;
	}
	scanf("%d", &N);
	for (int sla = 0; sla < N; sla++)
	{
		for (int i = 0; i < 26; i++) AdjList[i].clear();
		for (int i = 0; i < 26; i++) Visit[i] = 0;
		scanf("%d %d", &Ver, &E);
		while (E--)
		{
			scanf(" %c %c", &Ar1, &Ar2);
			AdjList[myMapi[Ar1]].push_back(myMapi[Ar2]);
			AdjList[myMapi[Ar2]].push_back(myMapi[Ar1]);
		}

		Count = 0;
		printf("Case #%d:\n", sla + 1);
		for (int i = 0; i < Ver; i++)
		{
			Cesto.clear();
			if (!Visit[i])
			{
				Count++;
				dfs(i);
				sort(Cesto.begin(), Cesto.end());
				for (int i = 0; i < Cesto.size(); i++)
					printf("%c,", myMapc[Cesto[i]]);
				printf("\n");
			}
		}
		printf("%d connected components\n\n", Count);
	}
}