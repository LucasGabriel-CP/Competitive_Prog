#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
    int i;
    i = 1;
    for (int j = 60; j >= 0; j-= 5)
    {
        cout << "I=" << i << " J=" << j << '\n';
        i += 3;
    }
}