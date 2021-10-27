#include <iostream>

using namespace std;

int main()
{
    int N, i, NumMat, MaiorMat;
    float Nota, MaiorNota = 0;
    cin >> N;
    for (i = 1; i <= N; i++)
    {
        cin >> NumMat >> Nota;
        if (Nota > MaiorNota)
        {
            MaiorNota = Nota;
            MaiorMat = NumMat;
        }
    }
    if (MaiorNota < 8)
        cout << "Minimum note not reached" << '\n';
    else
        cout << MaiorMat << '\n';
}