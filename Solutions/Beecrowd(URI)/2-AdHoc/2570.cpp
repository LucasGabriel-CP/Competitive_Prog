#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define forr(i, l, r) for (int i = (int)(l); i < (int)(r); ++i)

typedef pair<int, int> ii;
typedef pair<char, int> ci;
typedef vector< int > vi;
typedef vector<vector<int>> vvi;

int main()
{
	int N, M, K, row, Count = 0, id = 0; scanf("%d %d %d", &N, &M, &K);
	vvi Matrix(N, vi(M, -1));
	vi RHCP(4, 0);
	map< ci, ii > myMap;
	char W;
	while (K--)
	{
		scanf(" %c %d", &W, &row);
		row--;
		myMap[{W, row}] = { id, Count };
		id = (id + 1) % 4;
		Count++;
	}

	forn(i, N)
	{
		forn(j, M)
		{
			if (!myMap.count({ 'L', i }) && !myMap.count({ 'C', j }))
				continue;
			if (!myMap.count({ 'L', i }))
				RHCP[myMap[{'C', j}].f]++;
			else
				if (!myMap.count({ 'C', j }))
					RHCP[myMap[{'L', i}].f]++;
				else
					if (myMap[{'L', i}].s > myMap[{'C', j}].s)
						RHCP[myMap[{'L', i}].f]++;
					else
						RHCP[myMap[{'C', j}].f]++;
		}
	}

	printf("R%d H%d C%d P%d\n", RHCP[0], RHCP[1], RHCP[2], RHCP[3]);

	return 0;
}