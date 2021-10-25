#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
    int i;
    i = 1;
    for (int j = 7; j >= 5; j--)
        cout << "I=" << i << " J=" << j << '\n';
    i += 2;
    for (int j = 9; j >= 7; j--)
        cout << "I=" << i << " J=" << j << '\n';
    i += 2;
    for (int j = 11; j >= 9; j--)
        cout << "I=" << i << " J=" << j << '\n';
    i += 2;
    for (int j = 13; j >= 11; j--)
        cout << "I=" << i << " J=" << j << '\n';
    i += 2;
	for (int j = 15; j >= 13; j--)
        cout << "I=" << i << " J=" << j << '\n';
}