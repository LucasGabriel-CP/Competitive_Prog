#include <iostream>

using namespace std;
int MelhorResp = 0;

void Func(int Ct, int Cnt, int Best, int Vet[])
{
    if (Best < MelhorResp)
        return;
        
    if  (Cnt == 0)
    {
        MelhorResp = Best;
        return;
    }

    if  (Ct < 0)
        return;
            
    Func(Ct - 1, Cnt, Best, Vet);
    Func(Ct - 1, Cnt - 1, Best & Vet[Ct], Vet);

    return;
}


int main()
{
    int K, N, T,
        Vet[1010];

    cin >> T;
    for (int i = 0; i < T; i++)
    {	
        cin >> N >> K;
        for (int j = 0; j < N; j++)
            cin >> Vet[j];
            
        int Best = (1 << 30) - 1;
        MelhorResp = 0;
        
        Func(N - 1, K, Best, Vet);
        cout << MelhorResp << '\n';
    }
}