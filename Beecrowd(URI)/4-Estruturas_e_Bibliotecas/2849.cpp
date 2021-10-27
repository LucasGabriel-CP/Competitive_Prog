#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100005
#define f first
#define s second
#define Mid ((l + r) >> 1)

typedef vector< int > vi;
typedef long long ll;
typedef int no;

int indx[MAX_N];
int N;
vi Seg[4 * MAX_N];
map<ll, vi> aux;
ll Vet[MAX_N];

void build(int id = 1, int l = 0, int r = N - 1)
{
    if (l == r)
    {
        Seg[id].push_back(indx[l]);
        return;
    }
    build(2 * id, l, Mid);
    build(2 * id + 1, Mid + 1, r);
    merge(Seg[2 * id].begin(), Seg[2 * id].end(), Seg[2 * id + 1].begin(), Seg[2 * id + 1].end(), back_inserter(Seg[id]));
}

int Solve(int i, int j, int k, int l = 0, int r = N - 1, int id = 1)
{
    if (l == r)
        return Seg[id][0];
    int pj = upper_bound(Seg[2 * id].begin(), Seg[2 * id].end(), j) - Seg[2 * id].begin();
    int pi = lower_bound(Seg[2 * id].begin(), Seg[2 * id].end(), i) - Seg[2 * id].begin();
    int diff = pj - pi;
    if (diff >= k)
        return Solve(i, j, k, l, Mid, 2 * id);
    return Solve(i, j, k - diff, Mid + 1, r, 2 * id + 1);
}

int main()
{
    int Q; scanf("%d %d", &N, &Q);
    map<int, int> myMap;
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &Vet[i]);
        indx[i] = i;
        aux[Vet[i]].push_back(i);
    }
    sort(indx, indx + N, [](int a, int b) {return Vet[a] < Vet[b]; });
    build();
    int L, R, K, G, D, Tot, Elem;
    while (Q--)
    {
        scanf("%d %d %d %d %d", &L, &R, &K, &G, &D);
        L--; R--;
        Elem = Solve(L, R, K);
        Tot = (upper_bound(aux[Vet[Elem]].begin(), aux[Vet[Elem]].end(), R)
            - lower_bound(aux[Vet[Elem]].begin(), aux[Vet[Elem]].end(), L));
        G = abs(G - Tot);
        D = abs(D - Tot);
        printf("%lld %d %c\n", Vet[Elem], Tot, G < D ? 'G' : G > D ? 'D' : 'E');
    }

    return 0;
}