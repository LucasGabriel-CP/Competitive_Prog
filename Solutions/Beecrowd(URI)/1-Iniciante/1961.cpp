#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int NCanos, AltCano, Pulo, vet[100];
    bool Tururu = 1;
    cin >> Pulo >> NCanos;
    cin >> AltCano;
    vet[0] = AltCano;
    for (int i=1; i < NCanos; i++)
    {
        cin >> AltCano;
        vet[i] = AltCano;
    }
    for (int i = 1; i < NCanos && Tururu == 1; i++)
    {
        if (vet[i] - vet[i - 1] > Pulo)
        {
            cout << "GAME OVER" << '\n';
            Tururu = 0;
        }
        else if (vet[i] < vet[i - 1] - Pulo)
        {
            cout << "GAME OVER" << '\n';
            Tururu = 0;
        }
    }
    if (Tururu == 1)
        cout << "YOU WIN" << '\n';
}