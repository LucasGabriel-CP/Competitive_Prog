#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

typedef pair<int, int> ii;
typedef vector< int > vi;
typedef vector<pair<int, int>> vii;
typedef vector<vector<int>> vvi;


pair< int, int > Lalala(vii Posi, vvi Mat)
{
    for (int i = 0; i < Posi.size(); i++)
    {
        if (Mat[Posi[i].f - 1][Posi[i].s - 1] == 7 && Mat[Posi[i].f - 1][Posi[i].s] == 7 && Mat[Posi[i].f - 1][Posi[i].s + 1] == 7)
            if (Mat[Posi[i].f][Posi[i].s - 1] == 7 && Mat[Posi[i].f][Posi[i].s + 1] == 7)
                if (Mat[Posi[i].f + 1][Posi[i].s - 1] == 7 && Mat[Posi[i].f + 1][Posi[i].s] == 7 && Mat[Posi[i].f + 1][Posi[i].s + 1] == 7)
                    return Posi[i];
    }
    return make_pair(0, 0);
}

int main()
{
    vii Quar;
    vvi Matriz;
    int N, M; scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        vi Aux;
        for (int j = 0; j < M; j++)
        {
            int T; scanf("%d", &T);
            Aux.push_back(T);
            if (i > 0 && i < N - 1 && j > 0 && j < M - 1 && T == 42)
                Quar.push_back(make_pair(i, j));
        }
        Matriz.push_back(Aux);
    }


    ii myP = Lalala(Quar, Matriz);

    if (myP.f != 0)
        printf("%d %d\n", myP.f + 1, myP.s + 1);
    else
        printf("%d %d\n", myP.f, myP.s);
}