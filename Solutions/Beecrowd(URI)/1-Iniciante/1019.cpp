#include <iostream>

using namespace std;

int main()
{
    int s, r;
    cin >> s;
    cout << s / 3600 << ":";
    r = (s % 3600);
    cout << r / 60 << ":";
    r = (r % 60);
    cout << r / 1 << "\n";
    r = (r % 1);
}