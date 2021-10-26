#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

bool ordena(int a, int b)
{
    if	(a > b)
        return 1;
    return 0;
}

int main()
{
    int Ans, M, N, P;
    cin >> N;
    for	(int i = 0; i < N; i++)
    {
        vector< int > Vet, VetOrd;
        Ans = 0;
        cin >> M;
        for	(int j = 0; j < M; j++)
        {
            cin >> P;
            Vet.push_back(P);
            VetOrd.push_back(P);
        }
        sort(VetOrd.begin(),VetOrd.end(), ordena);
        for	(int j = 0; j < M; j++)
        {
            if	(Vet[j] == VetOrd[j])
                Ans++;
        }
        cout << Ans << '\n';
    }
}