#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double x, y, media;
    cin >> x >> y;
    cout << fixed << setprecision(3);
    media = x / y;
    cout << media << " km/l" << "\n";
}