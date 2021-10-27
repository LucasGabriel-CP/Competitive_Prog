#include<bits/stdc++.h>

using namespace std;

#define f first
#define s second

typedef pair<int, int> ii;
typedef vector< int > vi;
typedef vector<pair<int, int>> vii;

bool Comp(ii a, ii b)
{
	if (a.f < b.f)
		return true;
	if (a.f > b.f)
		return false;
	return a.s < b.s;
}

int LIS(vii a)
{
	vi c(a.size(), 1);
	vi b(a.size(), 1);
	for (int i = 1; i < a.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[i].f > a[j].f)
			{
				if (a[i].s == a[j].s + 2)
					c[i] = max(c[i], b[j] + 1);
				else
					if (a[i].s == a[j].s - 2)
						b[i] = max(b[i], c[j] + 1);
			}
		}
	}
	int Ans = 0;
	for (int i = 0; i < a.size(); i++)
	{
		Ans = Ans > b[i] ? (Ans > c[i] ? Ans : c[i]) : (b[i] > c[i] ? b[i] : c[i]);
	}
	return Ans;
}

int main()
{
	int N;
	while (scanf("%d", &N) != EOF)
	{
		vii Cord;
		while (N--)
		{
			int X, Y;
			scanf("%d %d", &X, &Y);
			Cord.push_back({ X, Y });
		}
		sort(Cord.begin(), Cord.end(), Comp);
		printf("%d\n", LIS(Cord));
	}

	return 0;
}