#include <iostream>

using namespace std;

int main()
{
    int Teste, Cara, Digi,
    Conso, Num, Total, j;
    cin >> Teste;
    for (int i = 0; i < Teste; i++)
    {
        Conso = 26;
        Num = 10;
        Total = 0;
        cin >> Cara >> Digi;
        for (j = 1; j < Cara; j++)
        {
            Conso *= 26;
        }
        for (int k = 1; k < Digi; k++)
        {
            Num = Num * 10;
        }
        if (Cara == 0)
           Conso = 1;
        if (Digi == 0)
            Num = 1;
        Total = Num * Conso;	 
        if (Cara == 0 && Digi == 0)
           Total = 0;
        cout << Total << '\n';
    }
}