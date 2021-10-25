#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    float A, B, C;
    cout << fixed  << setprecision(1);
    cin  >> A >> B >> C;
    if (abs(B - C) < A && A < (B + C)) 
        cout << "Perimetro = " << A + B + C << "\n";
    else 
        cout << "Area = " << ((A + B)*C) / 2 << "\n";
}