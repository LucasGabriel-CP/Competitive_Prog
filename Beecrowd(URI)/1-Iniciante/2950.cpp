#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    float N, X, Y, ICM;
    cout << fixed << setprecision (2);
    cin >> N >> X >> Y;
    ICM = N / (X + Y);
    cout << ICM << "\n";
}