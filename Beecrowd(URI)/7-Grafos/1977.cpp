#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define inf 1000000000

typedef pair<string, int> si;
typedef pair<int, string> is;

map< string, vector<si> > AdjList;
map< string, int > Dist;
set< string > mySet;

int JaNumSei(string O, string D)
{
	for (auto it : mySet)
		Dist[it] = inf;

	priority_queue<is, vector<is>, greater<is>> myPq;
	myPq.push(is(0, O));
	Dist[O] = 0;
	while (!myPq.empty())
	{
		string Fon = myPq.top().s;
		myPq.pop();
		for (int i = 0; i < AdjList[Fon].size(); i++)
		{
			string V = AdjList[Fon][i].f;
			int W = AdjList[Fon][i].s;
			if (Dist[V] > Dist[Fon] + W)
			{
				Dist[V] = Dist[Fon] + W;
				myPq.push(is(Dist[V], V));
			}
		}
	}
	return Dist[D];
}

int main()
{
	int X, N, M, P;
	while (scanf("%d %d %d", &X, &M, &N), X || N || M)
	{
		for (int i = 0; i < M; i++)
		{
			char V1[256], V2[256];
			scanf("%s %s %d", V1, V2, &P);
			AdjList[V1].push_back(si(V2, P));
			mySet.insert(V1);
			mySet.insert(V2);
		}

		int Min, Hor, Ans = JaNumSei("varzea", "alto");
		if (X <= 30)
			Ans += 30;
		else
			Ans += 50;
		Hor = (Ans / 60) + 17;
		Min = Ans % 60;

		printf("%d:%02d\n", Hor % 24, Min);
		if (Ans <= 60)
			printf("Nao ira se atrasar\n");
		else
			printf("Ira se atrasar\n");
		AdjList.clear();
		mySet.clear();
	}
	return 0;
}