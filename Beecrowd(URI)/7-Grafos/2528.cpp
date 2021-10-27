#include <bits/stdc++.h>

using namespace std;

#define sz 4050
#define f first
#define s second
#define inf 214700000

typedef pair<int, int> ii;
typedef vector<pair<int, int>> vii;

int Visit[sz];
vii AdjList[sz];

int x[] = { 0,-1,0,1 }, y[] = { -1,0,1,0 };

int main()
{
	int N, M;
	priority_queue< ii > myPq;

	while (scanf("%d %d", &N, &M) != EOF)
	{
		for (int i = 0; i < sz; i++) Visit[i] = inf;

		for (int i = 0; i < M; i++)
		{
			int A, B; scanf("%d %d", &A, &B);
			AdjList[A].push_back(ii(1, B));
			AdjList[B].push_back(ii(1, A));
		}
		int Com, Fim, E; scanf("%d %d %d", &Com, &Fim, &E);

		myPq.push(ii(0, Com));
		Visit[Com] = 0;
		while (!myPq.empty())
		{
			ii Fon = myPq.top();
			myPq.pop();
			for (int i = 0; i < AdjList[Fon.s].size(); i++)
			{
				ii V = AdjList[Fon.s][i];
				if (V.s != E && Visit[V.s] > Visit[Fon.s] + V.f)
				{
					Visit[V.s] = Visit[Fon.s] + V.f;
					myPq.push(V);
				}
			}
		}
		printf("%d\n", Visit[Fim]);

		for (int i = 0; i < sz; i++) AdjList[i].clear();
	}
}