#include <iostream>

using namespace std;

int main()
{
    string CPF;
    int RestoB1, RestoB2;
    while(cin >> CPF)
    {
        long SomaB1 = 0, SomaB2 = 0;
        for(int i = 0, j = 9, k = 1; i < 11; i++)
        {
            if(CPF[i] != '.' && CPF[i] != '-')
            {
                SomaB1 += (CPF[i] - 48) * k; 
                SomaB2 += (CPF[i] - 48) * j;
                j--;
                k++;
            }
        }
        RestoB1 = SomaB1 % 11;
        if(RestoB1 == 10)
            RestoB1 = 0;
        RestoB2 = SomaB2 % 11;
        if(RestoB2 == 10)
            RestoB2 = 0;
        if(CPF[12] != char(RestoB1 + 48) || CPF[13] != char(RestoB2 + 48))
            cout << "CPF invalido" << '\n';
        else
            cout << "CPF valido" << '\n';

    }
}