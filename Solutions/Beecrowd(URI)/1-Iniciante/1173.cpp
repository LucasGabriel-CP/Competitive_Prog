#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int V, N[10];
    cin >> V;
    for (int i = 0; i < 10; i++)
    {
        N[i] = V;
        V *= 2;
        cout << "N[" << i << "] = "
            << N[i] << '\n';
    }
}