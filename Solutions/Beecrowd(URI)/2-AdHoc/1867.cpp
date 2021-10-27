#include <iostream>
#include <string>

using namespace std;

int main()
{
    int SomaNum1 = 0, SomaNum2 = 0, Soma = 0,
        Result1, Result2;
    string Num1, Num2;
    cin >> Num1 >> Num2;
    while(Num1 != "0" || Num2 != "0")
    {
        SomaNum1 = 0;
        SomaNum2 = 0;
        Soma = 0;
        for(int i = 0; i < Num1.size(); i++)
        {
            SomaNum1 = SomaNum1 + (char)Num1[i] - 48;
        }
        for(int i = 0; i < Num2.size(); i++)
        {
            SomaNum2 = SomaNum2 + (char)Num2[i] - 48;
        }
        if (SomaNum1 < 10 )
            Result1 = SomaNum1;
        else
        {
            while(SomaNum1!=0)	
            {
                Soma += SomaNum1 % 10; 
                SomaNum1 /= 10;
            }
            Result1 = Soma;
        }
        if (SomaNum2 < 10)
            Result2 = SomaNum2;
        else
        {
            Soma = 0;
            while(SomaNum2!=0)	
            {
                Soma += SomaNum2 % 10; 
                SomaNum2 /= 10;
            }
            Result2 = Soma;
        }
        if(Result1 > Result2)
            cout <<  "1" << '\n';
        else if(Result1 < Result2)
            cout << "2" << '\n';
        else
            cout << "0" << '\n';
        cin >> Num1 >> Num2;
    }
}