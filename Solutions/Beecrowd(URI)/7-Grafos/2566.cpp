#include <bits/stdc++.h>

using namespace std;

#define sz 10150
#define f first
#define s second
#define inf 1000000

typedef pair<int, int> ii;
typedef vector<pair<int, int>> vii;

int  N, M, Visit[sz];
priority_queue< ii > myPq;

int dijkstra(vii AdjList[])
{
	for (int i = 0; i < N; i++) Visit[i] = inf;
	int Orig = 0;
	myPq.push(ii(0, Orig));
	Visit[Orig] = 0;
	while (!myPq.empty())
	{
		ii Fon = myPq.top();
		myPq.pop();
		for (int i = 0; i < AdjList[Fon.s].size(); i++)
		{
			ii V = AdjList[Fon.s][i];
			if (Visit[V.s] > Visit[Fon.s] + V.f)
			{
				Visit[V.s] = Visit[Fon.s] + V.f;
				myPq.push(V);
			}
		}
	}
	return Visit[N - 1];
}

int main()
{
	int Bum, Mil, A, B, R, T;
	while (scanf("%d %d", &N, &M) != EOF)
	{
		vii Air[N], Bus[N];
		for (int i = 0; i < M; i++)
		{
			scanf("%d %d %d %d", &A, &B, &T, &R);
			A--;
			B--;
			if (T)
			{
				Bus[A].push_back(ii(R, B));
			}
			else
			{
				Air[A].push_back(ii(R, B));
			}
		}

		Bum = dijkstra(Bus);
		Mil = dijkstra(Air);
		if (Bum < Mil)
			printf("%d\n", Bum);
		else
			printf("%d\n", Mil);
	}
}