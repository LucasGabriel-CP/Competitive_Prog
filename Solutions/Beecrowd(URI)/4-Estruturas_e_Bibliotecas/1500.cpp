#include <bits/stdc++.h>

using namespace std;

#define MAX_N 400005

typedef long long ll;

vector< ll > Seg;
vector< ll >  Lazy;
int N;

void Update(int id, int l, int r, ll x)
{
	Lazy[id] += x;
	Seg[id] += (r - l) * x;
}

void Shift(int id, int l, int r)
{
	int mid = (l + r) / 2;
	Update(id * 2, l, mid, Lazy[id]);
	Update(id * 2 + 1, mid, r, Lazy[id]);
	Lazy[id] = 0;
}

void Increase(int x, int y, int v, int id = 1, int l = 0, int r = N)
{
	if (x >= r || l >= y) return;
	if (x <= l && r <= y)
	{
		Update(id, l, r, v);
		return;
	}
	Shift(id, l, r);
	int Mid = (l + r) / 2;
	Increase(x, y, v, id * 2, l, Mid);
	Increase(x, y, v, id * 2 + 1, Mid, r);
	Seg[id] = Seg[id * 2] + Seg[id * 2 + 1];
}

ll Solve(int x, int y, int id = 1, int l = 0, int r = N)
{
	if (x >= r || l >= y) return 0;
	if (x <= l && r <= y) return Seg[id];

	Shift(id, l, r);
	int Mid = (l + r) / 2;
	return Solve(x, y, id * 2, l, Mid) + Solve(x, y, id * 2 + 1, Mid, r);
}

int main()
{
	int T; scanf("%d", &T);
	int Op, l, r, val;
	while (T--)
	{
		Seg.assign(MAX_N, 0);
		Lazy.assign(MAX_N, 0);
		int C; scanf("%d %d", &N, &C);
		while (C--)
		{
			scanf("%d %d %d", &Op, &l, &r);
			if (l > r)
				swap(l, r);
			if (!Op)
			{
				scanf("%d", &val);
				Increase(l - 1, r, val);
			}
			else
			{
				printf("%lld\n", Solve(l - 1, r));
			}
		}
		Seg.clear();
		Lazy.clear();
	}

	return 0;
}