#include <bits/stdc++.h>

using namespace std;

#define inf ~(1<<31)

typedef vector< int > vi;

vector<vi> AdjList;
int N, M;

int main()
{
    int Count = 1;
    while (scanf("%d %d", &N, &M), N || M)
    {
        AdjList.assign(N, vi(N, inf));
        for (int i = 0; i < M; i++)
        {
            int A, B, P;
            scanf("%d %d %d", &A, &B, &P);
            A--;	B--;
            AdjList[A][B] = P;
            AdjList[B][A] = P;
        }
        for (int k = 0; k < N; ++k) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    if (AdjList[i][k] != inf && AdjList[k][j] != inf)
                        AdjList[i][j] = min(AdjList[i][j], max(AdjList[i][k], AdjList[k][j]));
                }
            }
        }
        int Q; scanf("%d", &Q);
        vector<int> Ans;
        while (Q--)
        {
            int O, D;  scanf("%d %d", &O, &D);
            Ans.push_back(O == D ? 0 : AdjList[O - 1][D - 1]);
        }
        printf("Instancia %d\n", Count++);
        for (int i = 0; i < Ans.size(); i++)
            printf("%d\n", Ans[i]);
        printf("\n");
    }
}