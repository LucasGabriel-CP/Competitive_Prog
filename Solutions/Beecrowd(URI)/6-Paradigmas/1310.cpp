#include <bits/stdc++.h>

using namespace std;

typedef vector< int > vi;

void Solve(vi& Vet)
{
    int ans = Vet[0], ans_l = 0, ans_r = 0;
    int sum = 0, minus_pos = -1;
    int n = (int)Vet.size();
    for (int r = 0; r < n; ++r) {
        sum += Vet[r];
        if (sum > ans) {
            ans = sum;
            ans_l = minus_pos + 1;
            ans_r = r;
        }
        if (sum < 0) {
            sum = 0;
            minus_pos = r;
        }
    }
    printf("%d\n", ans < 0 ? 0 : ans);
}

int main()
{
    int N, Custo;

    while (scanf("%d", &N) != EOF)
    {
        vi Vet;
        scanf("%d", &Custo);
        for (int i = 0; i < N; i++)
        {
            int Val;	scanf("%d", &Val);
            Vet.push_back(Val - Custo);
        }
        Solve(Vet);
    }

    return 0;
}