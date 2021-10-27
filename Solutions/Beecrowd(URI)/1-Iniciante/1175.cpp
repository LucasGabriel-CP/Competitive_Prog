#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N[20], i, y;
    for (i = 0; i < 20; i++)
    {
        cin >> N[i];
    }
    for (i = 0, y = 19; i < 20; i++, y--)
    {
        if (i < 10)
        swap (N[i], N[y]);
        cout << "N[" << i
            << "] = " << N[i] << '\n';
    }	
}