#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100005
#define f first
#define s second
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define Mid ((l + r) >> 1)

typedef pair<int, int> ii;
typedef ii no;

int N;
int lazy[4 * MAX_N];
no Seg[4 * MAX_N], Vet[MAX_N];

void Modify(no& t, no& a, no& b)
{
    if (a.f > b.f)
    {
        t = a;
        return;
    }
    if (b.f > a.f)
    {
        t = b;
        return;
    }
    t.f = a.f;
    t.s = min(a.s, b.s);
}

void muda(int& la, no& t)
{
    t.f += la;
}

void prop(int id, int l, int r)
{
    if (lazy[id])
    {
        muda(lazy[id], Seg[id]);
        if (l != r)
        {
            lazy[2 * id] += lazy[id];
            lazy[2 * id + 1] += lazy[id];
        }
        lazy[id] = 0;
    }
}

void build(int id = 1, int l = 0, int r = N - 1)
{
    lazy[id] = 0;
    if (l == r)
        Seg[id] = Vet[l];
    else
    {
        build(2 * id, l, Mid);
        build(2 * id + 1, Mid + 1, r);
        Modify(Seg[id], Seg[2 * id], Seg[2 * id + 1]);
    }
}

void Update(int i, int j, int x, int l = 0, int r = N - 1, int id = 1)
{
    if (i <= l && r <= j)
    {
        lazy[id] += x;
        prop(id, l, r);
        return;
    }
    prop(id, l, r);
    if (r < i || j < l)
        return;

    Update(i, j, x, l, Mid, 2 * id);
    Update(i, j, x, Mid + 1, r, 2 * id + 1);

    Modify(Seg[id], Seg[2 * id], Seg[2 * id + 1]);
}

no query(int i, int j, int l = 0, int r = N - 1, int id = 1)
{
    if (r < i || j < l)
        return { -1, -1 };
    prop(id, l, r);
    if (i <= l && r <= j)
        return Seg[id];

    no Op1 = query(i, j, l, Mid, 2 * id);
    no Op2 = query(i, j, Mid + 1, r, 2 * id + 1);
    no ans = { -1, -1 };

    Modify(ans, Op1, Op2);
    return ans;
}

int main()
{
    int Q;
    while (scanf("%d %d", &N, &Q) != EOF)
    {
        forn(i, N)
        {
            int val; scanf("%d", &val);
            Vet[i] = { val, i };
        }
        build();
        while (Q--)
        {
            int a, b; char t;
            scanf(" %c %d %d", &t, &a, &b);
            if (t == 'C')
            {
                no ans = query(a - 1, b - 1);
                printf("%d\n", ans.s + 1);
            }
            else
            {
                int v; scanf("%d", &v);
                Update(a - 1, b - 1, v);
            }
        }
    }

    return 0;
}