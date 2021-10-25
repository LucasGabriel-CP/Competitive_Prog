#include <iostream>

using namespace std;

int main()
{
    double p;
    int N, b;
    cin >> p;
    cout << "NOTAS:" << "\n";
    N = p * 100;
    cout << N / 10000 << " nota(s) de R$ 100.00" << "\n";
    b = (N % 10000);
    cout << b / 5000 << " nota(s) de R$ 50.00" << "\n";
    b = (b % 5000);
    cout << b / 2000 << " nota(s) de R$ 20.00" << "\n";
    b = (b % 2000);
    cout << b / 1000 << " nota(s) de R$ 10.00" << "\n";
    b = (b % 1000);
    cout << b / 500 << " nota(s) de R$ 5.00" << "\n";
    b = (b % 500);
    cout << b / 200 << " nota(s) de R$ 2.00" << "\n";
    b = (b % 200);
    cout << "MOEDAS:" << "\n";
    cout << b / 100 << " moeda(s) de R$ 1.00" << "\n";
    b = (b % 100);
    cout << b / 50 << " moeda(s) de R$ 0.50" << "\n";
    b = (b % 50);
    cout << b / 25 << " moeda(s) de R$ 0.25" << "\n";
    b = (b % 25);
    cout << b / 10 << " moeda(s) de R$ 0.10" << "\n";
    b = (b % 10);
    cout << b / 5 << " moeda(s) de R$ 0.05" << "\n";
    b = (b % 5);
    cout << b << " moeda(s) de R$ 0.01" << "\n";
}