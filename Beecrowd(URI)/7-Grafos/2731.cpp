#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define inf ~(1<<31) - 1

typedef pair<int, int> ii;
typedef vector< int > vi;
typedef vector<pair<int, int>> vii;

vii AdjList[20];
vi Visit, P;

void Dijkstra(int O)
{
	Visit.assign(20, inf);
	P.assign(20, -1);

	priority_queue< ii, vii, greater<ii> > myPq;
	Visit[O] = 0;
	myPq.push({ 0, O });
	while (!myPq.empty())
	{
		ii Fon = myPq.top();
		myPq.pop();
		if (Fon.f != Visit[Fon.s]) continue;

		for (ii edge : AdjList[Fon.s])
		{
			int to = edge.f;
			int len = edge.s;
			if (Visit[Fon.s] + len < Visit[to])
			{
				Visit[to] = Visit[Fon.s] + len;
				P[to] = Fon.s;
				myPq.push({ Visit[to], to });
			}
		}
	}
	int Ans = Visit[0];
	Ans <= 120 ? printf("Will not be late.")
		: printf("It will be %d minutes late.", Ans - 120);
	printf(" Travel time - %d - best way - ", Ans);
	vi Path;
	for (int v = 0; v != O; v = P[v])
		Path.push_back(v);
	Path.push_back(O);
	for (int i = (int)Path.size() - 1; i > 0; i--)
		printf("%d ", Path[i] + 1);
	printf("%d\n", Path[0] + 1);
}

int main()
{
	int N, M;
	while (scanf("%d %d", &N, &M), N && M)
	{
		for (int i = 0; i < M; i++)
		{
			int a, b, t; scanf("%d %d %d", &a, &b, &t);
			a--; b--;
			AdjList[a].push_back({ b, t });
			AdjList[b].push_back({ a, t });
		}
		int S; scanf("%d", &S);
		Dijkstra(S - 1);
		for (int i = 0; i < N; i++) AdjList[i].clear();
	}

	return 0;
}