#include <iostream>

using namespace std;

int main ()
{
    int N, NLinha;
    cin >> N;
    NLinha = N * 4;
    for (int i = 1; i <= NLinha; i++)
    {
        if (i % 4 == 0)
            cout << "PUM" << '\n';
        else
            cout << i << " ";
    }
}