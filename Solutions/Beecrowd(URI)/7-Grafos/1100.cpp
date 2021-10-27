#include<bits/stdc++.h>

using namespace std;

#define sz 8
#define f first
#define s second
#define inf 1000000000

typedef pair<int, int> ii;

int Visit[sz][sz];

int main()
{
	char X[3], Y[3];
	while (scanf("%s %s", &X, &Y) != EOF)
	{
		ii xx = (ii(X[0] - 'a', X[1] - '0' - 1));
		ii yy = (ii(Y[0] - 'a', Y[1] - '0' - 1));

		for (int i = 0; i < sz; i++)
			for (int j = 0; j < sz; j++)
				Visit[i][j] = inf;

		queue< ii > myQueue;
		myQueue.push(xx);
		Visit[xx.f][xx.s] = 0;
		ii Fon = xx;
		while (!myQueue.empty() && Fon != yy)
		{
			Fon = myQueue.front();
			myQueue.pop();
			if (Fon.first < sz && Fon.second < sz)
			{
				ii V = (ii(Fon.f + 1, Fon.s + 2));
				if (V.f < sz && V.f >= 0 && V.s < sz && V.s >= 0 && Visit[V.f][V.s] > Visit[Fon.f][Fon.s] + 1)
				{
					Visit[V.f][V.s] = Visit[Fon.f][Fon.s] + 1;
					myQueue.push(V);
				}
				V = (ii(Fon.f - 1, Fon.s + 2));
				if (V.f < sz && V.f >= 0 && V.s < sz && V.s >= 0 && Visit[V.f][V.s] > Visit[Fon.f][Fon.s] + 1)
				{
					Visit[V.f][V.s] = Visit[Fon.f][Fon.s] + 1;
					myQueue.push(V);
				}
				V = (ii(Fon.f - 1, Fon.s - 2));
				if (V.f < sz && V.f >= 0 && V.s < sz && V.s >= 0 && Visit[V.f][V.s] > Visit[Fon.f][Fon.s] + 1)
				{
					Visit[V.f][V.s] = Visit[Fon.f][Fon.s] + 1;
					myQueue.push(V);
				}
				V = (ii(Fon.f + 1, Fon.s - 2));
				if (V.f < sz && V.f >= 0 && V.s < sz && V.s >= 0 && Visit[V.f][V.s] > Visit[Fon.f][Fon.s] + 1)
				{
					Visit[V.f][V.s] = Visit[Fon.f][Fon.s] + 1;
					myQueue.push(V);
				}
				V = (ii(Fon.f - 2, Fon.s + 1));
				if (V.f < sz && V.f >= 0 && V.s < sz && V.s >= 0 && Visit[V.f][V.s] > Visit[Fon.f][Fon.s] + 1)
				{
					Visit[V.f][V.s] = Visit[Fon.f][Fon.s] + 1;
					myQueue.push(V);
				}
				V = (ii(Fon.f - 2, Fon.s - 1));
				if (V.f < sz && V.f >= 0 && V.s < sz && V.s >= 0 && Visit[V.f][V.s] > Visit[Fon.f][Fon.s] + 1)
				{
					Visit[V.f][V.s] = Visit[Fon.f][Fon.s] + 1;
					myQueue.push(V);
				}
				V = (ii(Fon.f + 2, Fon.s + 1));
				if (V.f < sz && V.f >= 0 && V.s < sz && V.s >= 0 && Visit[V.f][V.s] > Visit[Fon.f][Fon.s] + 1)
				{
					Visit[V.f][V.s] = Visit[Fon.f][Fon.s] + 1;
					myQueue.push(V);
				}
				V = (ii(Fon.f + 2, Fon.s - 1));
				if (V.f < sz && V.f >= 0 && V.s < sz && V.s >= 0 && Visit[V.f][V.s] > Visit[Fon.f][Fon.s] + 1)
				{
					Visit[V.f][V.s] = Visit[Fon.f][Fon.s] + 1;
					myQueue.push(V);
				}
			}
		}
		printf("To get from %s to %s takes %d knight moves.\n", X, Y, Visit[yy.f][yy.s]);
	}

	return 0;
}