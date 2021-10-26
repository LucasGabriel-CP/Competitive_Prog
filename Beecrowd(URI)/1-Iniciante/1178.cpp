#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main ()
{
    double N[100];
    cout << fixed << setprecision(4);
    cin >> N[0];
    for (int i = 0; i < 100; i++)
    {
        cout << "N[" << i << "] = "
            << N[i] << '\n';
        N[i + 1] = N[i] / 2;
    }
}