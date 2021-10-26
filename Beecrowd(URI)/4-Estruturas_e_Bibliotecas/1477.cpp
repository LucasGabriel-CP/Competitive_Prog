#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100005
#define f first
#define s second
#define Mid ((l + r) >> 1)

typedef pair<int, pair<int, int>> iii;
typedef iii no;

int N, Vet[MAX_N];
int lazy[4 * MAX_N];
no Seg[4 * MAX_N];

void Modify(no& t, no& a, no& b)
{
    t.f = a.f + b.f;
    t.s.f = a.s.f + b.s.f;
    t.s.s = a.s.s + b.s.s;
}

void muda(int& la, no& t)
{
    if (la == 1)
    {
        int aux = t.f;
        t.f = t.s.s;
        t.s.s = t.s.f;
        t.s.f = aux;
    }
    else
    {
        swap(t.s.f, t.f);
        swap(t.s.s, t.s.f);
    }
}

void prop(int id, int l, int r)
{
    if (lazy[id])
    {
        muda(lazy[id], Seg[id]);
        if (l != r)
        {
            lazy[2 * id] = (lazy[2 * id] + lazy[id]) % 3;
            lazy[2 * id + 1] = (lazy[2 * id + 1] + lazy[id]) % 3;
        }
        lazy[id] = 0;
    }
}

void build(int id = 1, int l = 0, int r = N - 1)
{
    lazy[id] = 0;
    if (l == r)
        Seg[id] = { 1, {0, 0} };
    else
    {
        build(2 * id, l, Mid);
        build(2 * id + 1, Mid + 1, r);
        Modify(Seg[id], Seg[2 * id], Seg[2 * id + 1]);
    }
}

void Update(int i, int j, int l = 0, int r = N - 1, int id = 1)
{
    if (i <= l && r <= j)
    {
        lazy[id] = (lazy[id] + 1) % 3;
        prop(id, l, r);
        return;
    }
    prop(id, l, r);
    if (r < i || j < l)
        return;

    Update(i, j, l, Mid, 2 * id);
    Update(i, j, Mid + 1, r, 2 * id + 1);

    Modify(Seg[id], Seg[2 * id], Seg[2 * id + 1]);
}

no query(int i, int j, int l = 0, int r = N - 1, int id = 1)
{
    if (r < i || j < l)
        return { 0, {0, 0} };
    prop(id, l, r);
    if (i <= l && r <= j)
        return Seg[id];

    no Op1 = query(i, j, l, Mid, 2 * id);
    no Op2 = query(i, j, Mid + 1, r, 2 * id + 1);
    no ans = { 0, {0, 0} };

    Modify(ans, Op1, Op2);
    return ans;
}

int main()
{
    int Q;
    while (scanf("%d %d", &N, &Q) != EOF)
    {
        build();
        while (Q--)
        {
            int a, b; char t;
            scanf(" %c %d %d", &t, &a, &b);
            if (t == 'C')
            {
                no ans = query(a - 1, b - 1);
                printf("%d %d %d\n", ans.f, ans.s.f, ans.s.s);
            }
            else
                Update(a - 1, b - 1);
        }
        printf("\n");
    }

    return 0;
}