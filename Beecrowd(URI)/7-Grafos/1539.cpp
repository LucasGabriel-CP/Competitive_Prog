#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define inf ~(1<<31)

typedef vector<pair< int, pair<int, int>>> viii;
typedef vector<vector<double>> vvf;
typedef long long ll;

int main()
{
    int N;
    while (scanf("%d", &N), N)
    {
        viii Id;
        vvf Matrix;
        Matrix.assign(N, vector<double>(110, inf));

        for (int i = 0; i < N; i++)
        {
            int x, y, p;
            scanf("%d %d %d", &x, &y, &p);
            Id.push_back({ x, {y, p} });
        }
        int Count = -1;
        for (int i = 0; i < (int)Id.size(); i++)
        {
            for (int j = 0; j < (int)Id.size(); j++)
            {
                double z = abs(sqrt((Id[j].f - Id[i].f) * (Id[j].f - Id[i].f) + (Id[j].s.f - Id[i].s.f) * (Id[j].s.f - Id[i].s.f)));
                if (z > Id[i].s.s) continue;
                Matrix[i][j] = z;
            }
        }

        for (int k = 0; k < N; ++k) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    if (Matrix[i][k] < inf && Matrix[k][j] < inf)
                        Matrix[i][j] = Matrix[i][j] - 1e-9 > Matrix[i][k] + Matrix[k][j] ? Matrix[i][k] + Matrix[k][j] : Matrix[i][j];
                }
            }
        }

        int Q; scanf("%d", &Q);
        vector<int> Ans;
        while (Q--)
        {
            int O, D;  scanf("%d %d", &O, &D);
            Ans.push_back(O == D ? 0 : (int)Matrix[O - 1][D - 1]);
        }
        for (int i = 0; i < (int)Ans.size(); i++)
            printf("%d\n", Ans[i] == inf || Ans[i] == -inf ? -1 : Ans[i]);
    }
}