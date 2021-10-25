#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double R, multiplicacao;
    cin >> R;
    multiplicacao = (4.0 / 3) * 3.14159 * R * R * R;
    cout << fixed << setprecision(3);
    cout << "VOLUME = " << multiplicacao << "\n";
}