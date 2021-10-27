#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    float V, A[100];
    cout << fixed << setprecision(1);
    for (int i = 0; i < 100; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < 100; i++)
    {
        if (A[i] <= 10)
        cout << "A[" << i << "] = " << A[i] << '\n';
    }
}