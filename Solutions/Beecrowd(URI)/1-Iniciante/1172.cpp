#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int Vec[10];
    for (int i = 0; i < 10; i++)
    {
        cin >> Vec[i];
        if (Vec[i] <= 0)
            Vec[i] = 1;
        cout << "X[" << i << "] = "
            << Vec[i] << '\n';
    }
}