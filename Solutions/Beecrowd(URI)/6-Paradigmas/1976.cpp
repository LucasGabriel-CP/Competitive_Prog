#include <bits/stdc++.h>

using namespace std;

#define MAX_N 1005
#define inf ~(1<<31) - 1
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define forr(i, l, r) for (int i = (int)(l); i < (int)(r); ++i)

int Vet[MAX_N], tableM[MAX_N][MAX_N], tableS[MAX_N][MAX_N];

void printPar(int i, int j, int n, int& id)
{
    if (i == j)
    {
        cout << 'A' << id++;
        return;
    }

    cout << '(';
    printPar(i, tableS[i][j], n, id);
    printPar(tableS[i][j] + 1, j, n, id);
    cout << ')';
}

void solve(int N)
{
    bool more = false;
    forr(i, 1, N)
        tableM[i][i] = 0;

    forr(len, 2, N)
    {
        forr(i, 1, N - len + 1)
        {
            int j = i + len - 1; tableM[i][j] = inf;
            forr(k, i, j)
            {
                int q = tableM[i][k] + tableM[k + 1][j] + Vet[i - 1] * Vet[k] * Vet[j];
                if (q == tableM[i][j])
                    more = true;
                if (q < tableM[i][j])
                {
                    tableM[i][j] = q;
                    tableS[i][j] = k;
                }
            }
        }
    }
    int id = 1;
    if (!more)
    {
        printPar(1, N - 1, N, id);
        cout << '\n';
    }
    else
        cout << tableM[1][N - 1] << '\n';
}

int main()
{
    int N;
    ios_base::sync_with_stdio(false); cin.tie(0);
    while (cin >> N, N)
    {
        int Aux;
        forn(i, N)
            cin >> Vet[i] >> Aux;
        Vet[N] = Aux;
        solve(N + 1);
    }

    return 0;
}