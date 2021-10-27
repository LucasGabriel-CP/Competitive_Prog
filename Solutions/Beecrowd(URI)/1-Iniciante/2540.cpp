#include <iostream>

using namespace std;

int main()
{
    long int N, Voto, Sim;
    double  Total;
    while (cin >> N)
    {
        Sim = 0;
        Total = 1.0*N * (2.00 /3);
        for (int i = 0; i < N; i++)
        {
            cin >> Voto;
            if (Voto == 1)
            Sim += 1;	
        }
        if (Sim >= Total)
            cout << "impeachment" << '\n';	
        else
            cout << "acusacao arquivada" << '\n';
    }
}