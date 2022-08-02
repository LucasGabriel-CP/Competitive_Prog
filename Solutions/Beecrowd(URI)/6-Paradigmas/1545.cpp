//Maximar pontos adicionando de uma ponto e removendo
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
const int MAX_N = (int)1e4+5;
int N;

ll dp[2][MAX_N];

ll solve(vi Vet){
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j + i < N; ++j) {
            if (i & 1) {
                dp[0][j] = max(dp[1][j + 1] + Vet[j], dp[1][j] + Vet[j + i]);
            }
            else {
                dp[1][j] = max(dp[0][j], dp[0][j + 1]);
            }
        }
    }

    return dp[0][0];
}

int main(){
    while (scanf("%d", &N) != EOF){
        vi Vet(N + 5);
        for(int i = 0; i < N; ++i){
            scanf("%d", &Vet[i]);
        }
        printf("%lld\n", solve(Vet));
    }

    return 0;
}
