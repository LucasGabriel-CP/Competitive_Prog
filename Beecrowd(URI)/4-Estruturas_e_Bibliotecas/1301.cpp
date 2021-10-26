#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100005
#define Mid ((l + r)/2)

typedef vector< int > vi;
typedef char no;

int N;
char Vet[MAX_N];
no Seg[4 * MAX_N];
no nil = '+';

no blah(no a, no b)
{
    if (a == '0' || b == '0')
        return '0';
    if (a != b)
        return '-';
    return '+';
}

no build(int id = 1, int l = 0, int r = N - 1)
{
    if (l > r)
        return '+';
    if (l == r)
        return Seg[id] = Vet[l];
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
    while (scanf("%d %d", &N, &Q) != EOF)
    {
        for (int i = 0; i < N; i++)
        {
            int Val; scanf(" %d", &Val);
            Vet[i] = Val > 0 ? '+' : Val < 0 ? '-' : '0';
        }
        build();
        while (Q--)
        {
            char Op; scanf(" %c", &Op);
            if (Op == 'C')
            {
                int w, v; scanf("%d %d", &w, &v);
                Update(w - 1, v > 0 ? '+' : v < 0 ? '-' : '0');
            }
            else
            {
                int L, R; scanf("%d %d", &L, &R);
                L--; R--;
                printf("%c", Solve(min(L, R), max(L, R)));
            }
        }
        printf("\n");
    }
    return 0;
}