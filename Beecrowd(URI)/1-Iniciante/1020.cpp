#include <iostream>

using namespace std;

int main()
{
    int d, a;
    cin >> d;
    cout << d / 365 << " ano(s)" << "\n";
    a = (d % 365);
    cout << a / 30 << " mes(es)" << "\n";
    a = (a % 30);
    cout << a / 1 << " dia(s)" << "\n";
    a = (a % 1);
}