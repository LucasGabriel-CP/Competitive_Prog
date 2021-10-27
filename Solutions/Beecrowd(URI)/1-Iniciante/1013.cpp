#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    int a, b, c, MaiorAB, Maior;
    cin >> a >> b >> c;
    MaiorAB = (a + b + abs(a - b)) / 2;
    Maior = (MaiorAB + c + abs(c - MaiorAB)) / 2;
    cout << Maior << " eh o maior" << "\n";
}