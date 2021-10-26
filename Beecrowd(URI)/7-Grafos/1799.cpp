#include <bits/stdc++.h>

using namespace std;

#define sz 4050
#define f first
#define s second
#define inf 1000000

typedef pair<int, int> ii;
typedef vector< int > vi;
typedef vector<pair<int, int>> vii;

int Visit[sz];
vii AdjList[sz];

int x[] = { 0,-1,0,1 }, y[] = { -1,0,1,0 };

int main()
{
	int Aux, Com, Fim, Lig, Pon, Star;
	priority_queue< ii > myPq;
	map< string, int > myMap;
	map< string, int>::iterator it;
	scanf("%d %d", &Pon, &Lig);
	for (int i = 0; i < Lig; i++) Visit[i] = inf;
	int Cont = 0;
	for (int i = 0; i < Lig; i++)
	{
		string A, B; cin >> A >> B;
		if (A == "Entrada")
		{
			if (myMap.find(B) == myMap.end())
			{
				myMap[B] = Cont;
				Cont++;
			}
			Com = myMap[B];
		}
		else if (B == "Entrada")
		{
			if (myMap.find(A) == myMap.end())
			{
				myMap[A] = Cont;
				Cont++;
			}
			Com = myMap[A];
		}
		else
			if (B == "Saida")
			{
				if (myMap.find(A) == myMap.end())
				{
					myMap[A] = Cont;
					Cont++;
				}
				Fim = myMap[A];
			}
			else
				if (A == "Saida")
				{
					if (myMap.find(B) == myMap.end())
					{
						myMap[B] = Cont;
						Cont++;
					}
					Fim = myMap[B];
				}

				else
				{
					if (myMap.find(A) == myMap.end())
					{
						myMap[A] = Cont;
						Cont++;
					}
					if (myMap.find(B) == myMap.end())
					{
						myMap[B] = Cont;
						Cont++;
					}
					if (A == "*")
						Star = myMap[A];
					else
						if (B == "*")
							Star = myMap[B];

					AdjList[myMap[A]].push_back(ii(1, myMap[B]));
					AdjList[myMap[B]].push_back(ii(1, myMap[A]));
				}
	}

	myPq.push(ii(0, Com));
	Visit[Com] = 0;
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
	Aux = Visit[Star];

	for (int i = 0; i < Lig; i++) Visit[i] = inf;
	myPq.push(ii(0, Star));
	Visit[Star] = 0;
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

	printf("%d\n", Aux + 2 + Visit[Fim]);
}