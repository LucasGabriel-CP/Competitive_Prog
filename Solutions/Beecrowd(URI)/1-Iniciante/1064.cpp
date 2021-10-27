#include <iostream>
#include <iomanip>

using namespace std;

int main ()
{
    float Soma, N;
    int NumPosit;
    NumPosit = 0;
    for (int i = 0; i < 6; i++)
    {
        cin >> N;
        if (N > 0)
        {
            Soma += N;
            NumPosit ++;
        }
    }
    cout << fixed << setprecision (1) << NumPosit << " valores positivos" << "\n"
        << Soma / NumPosit << "\n";
}