#include <bits/stdc++.h>

using namespace std;

#define forr(i, l, r) for (int i = (int)(l); i < (int)(r); ++i)

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		int p; scanf("%d", &p);
		if (p == 1)
		{
			printf("%d\n", 1);
			continue;
		}
		if (p == 2)
		{
			printf("%d\n", 3);
			continue;
		}
		int Count = 1;
		int Ans = 2;
		forr(i, 2, p - 1)
		{
			if (i % 2 == 0)
				Count += 2;
			Ans = Ans + Count;
		}
		printf("%d\n", p * p - Ans);
	}

	return 0;
}