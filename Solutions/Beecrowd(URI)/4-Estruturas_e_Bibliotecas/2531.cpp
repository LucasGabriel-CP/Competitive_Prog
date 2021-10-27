#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100005
#define f first
#define s second
#define inf ~(1<<31) - 1
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define forr(i, l, r) for (int i = (int)(l); i < (int)(r); ++i)
#define Mid ((l + r)/2)

typedef pair<int, int> ii;
typedef vector< int > vi;
typedef ii no;

int N, Vet[MAX_N];
no Seg[4 * MAX_N];
no nil = { inf, -inf };

no blah(no a, no b)
{
    return { min(a.f, b.f), max(a.s,b.s) };
}

no build(int id = 1, int l = 0, int r = N - 1)
{
    if (l > r)
        return { inf,-inf };
    if (l == r)
        return Seg[id] = { Vet[l], Vet[l] };
    return Seg[id] = blah(build(2 * id, l, Mid), build(2 * id + 1, Mid + 1, r));
}

no Solve(int i, int j, int id = 1, int l = 0, int r = N - 1)
{
    if (r < i || j < l) return nil;
    if (i <= l && r <= j) return Seg[id];
    return blah(Solve(i, j, id * 2, l, Mid), Solve(i, j, id * 2 + 1, Mid + 1, r));
}

no Update(int i, no x, int id = 1, int l = 0, int r = N - 1)
{
    if (r < i || i < l) return Seg[id];
    if (l == r) return Seg[id] = x;
    return Seg[id] = blah(Update(i, x, id * 2, l, Mid), Update(i, x, id * 2 + 1, Mid + 1, r));
}

int main()
{
    int Q;
    while (scanf("%d", &N) != EOF)
    {
        for (int i = 0; i < N; i++)
        {
            scanf(" %d", &Vet[i]);
        }
        build();
        scanf("%d", &Q);
        while (Q--)
        {
            int Op; scanf("%d", &Op);
            if (Op == 1)
            {
                int w, v; scanf("%d %d", &w, &v);
                Update(w - 1, { v,v });
            }
            else
            {
                int L, R; scanf("%d %d", &L, &R);
                L--; R--;
                ii Ans = Solve(min(L, R), max(L, R));
                printf("%d\n", abs(Ans.f - Ans.s));
            }
        }
    }
    return 0;
}