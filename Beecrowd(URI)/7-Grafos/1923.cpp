#include <bits/stdc++.h>

using namespace std;

typedef vector< int > vi;

vector<bool> Visit;
vector<string> id;
vi AdjList[1050];
int G;
int Timer = 1;
set< string> myPq;

void BFS(int Source)
{
	queue<int> myQueue;
	vector<int> Visit(1050);
	vi Dist(1050);
	int Timer = 0;
	myQueue.push(Source);
	Visit[Source] = true;
	Dist[Source] = 0;
	while (!myQueue.empty())
	{
		int v = myQueue.front();
		myQueue.pop();
		if (Dist[v] == G) break;
		for (int u : AdjList[v])
		{
			if (!Visit[u])
			{
				Visit[u] = true;
				myQueue.push(u);
				myPq.insert(id[u - 1]);
				Dist[u] = Dist[v] + 1;
			}
		}
	}
	cout << myPq.size() << '\n';
	for (auto i : myPq)
		cout << i << '\n';
}

int main()
{
	int N; cin >> N >> G;
	Visit.assign(N, false);
	map<string, int> myMap;
	id.assign(N, "");
	myMap["Rerisson"] = 0;
	int Count = 1;
	for (int i = 0; i < N; i++)
	{
		string S, T;
		cin >> S >> T;
		if (!myMap.count(S))
		{
			id[Count - 1] = S;
			myMap[S] = Count++;
		}
		if (!myMap.count(T))
		{
			id[Count - 1] = T;
			myMap[T] = Count++;
		}
		AdjList[myMap[S]].push_back(myMap[T]);
		AdjList[myMap[T]].push_back(myMap[S]);
	}
	BFS(0);

	return 0;
}