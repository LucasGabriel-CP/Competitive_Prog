#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int Par[5], Impar[5], p = 0, im = 0,
    Valor, j;
    for (int i = 0; i < 15; i++)
    {
        cin >> Valor;
        if (Valor % 2 == 0)
        {
            Par[p] = Valor;
            p++;
        }
        else if (Valor % 2 != 0)
        {
            Impar[im] = Valor;
            im++;
        }
        if (p == 5)
        {
            for (j = 0; j < 5; j++)
            {
                cout << "par[" << j << "] = "
                    << Par[j] << '\n';
            }
            p = 0;
        }
        if (im == 5)
        {
            for (j = 0; j < 5; j++)
            {
                cout << "impar[" << j << "] = "
                    << Impar[j] << '\n';
            }
            im = 0;
        }
    }
    if (im != 0)
    {
        for (j = 0; j < im; j++)
        {
            cout << "impar[" << j << "] = "
                << Impar[j] << '\n';
        }
    }
    if (p != 0)
    {
        for (j = 0; j < p; j++)
        {
            cout << "par[" << j << "] = "
                << Par[j] << '\n';
        }
    }
}