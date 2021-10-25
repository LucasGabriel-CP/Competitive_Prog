#include <iostream>
#include <iomanip>

using namespace std;

int main ()
{
    int N;
    cin >> N;
    for (int i = 2; i < 10000; i += 1)
    {
        if (i % N == 2)
            cout << i << '\n';
    }
}