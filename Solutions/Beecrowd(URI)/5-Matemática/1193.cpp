#include <iostream>
#include <sstream>
#include <string.h>
#include <iomanip>
#include <stdlib.h>

using namespace std;
long long i, j;

void ConvertDecToBin(long long int BinNum[], long long Num)
{
    for(i = 0; Num > 0; i++)
    {
        BinNum[i] = Num % 2;
        Num = Num / 2;
    }
}

string ConvertDecToHex(long long Dec)
{
    string Result = "";
    long long Rem;
    while(Dec != 0)
    {
        Rem = Dec % 16;
        if (Rem > 9)
        {
            switch(Rem)
            {
                case 10: Result = "a" + Result; break;
                case 11: Result = "b" + Result; break;
                case 12: Result = "c" + Result; break;
                case 13: Result = "d" + Result; break;
                case 14: Result = "e" + Result; break;
                case 15: Result = "f" + Result; break;
            }
        }
        else
        {
            Result = char(Rem + 48) + Result; 
        }
        Dec /= 16;
    }
    return Result;
}

long int ConvertBinToDec(string NumB)
{
    long int Dec = 0;
    for(i = 0; i < NumB.size(); i++)
    {
        if(NumB[i] == '1')
            Dec = (Dec * 2) + 1;
        if(NumB[i] == '0')
            Dec = (Dec * 2);
    }
    return Dec;
}

long int ConvertHexToDec(string NumHex)
{
    long long Rem = 0, Base = 1;
    for(i = NumHex.size(); i >= 0; i--)
    {
        if(NumHex[i] >= '0' && NumHex[i] <= '9')
        {
            Rem  = Rem + (NumHex[i] - 48) * Base;
            Base = Base * 16;
        }
        else if(NumHex[i] >= 'a' && NumHex[i] <= 'f')
        {
            Rem  = Rem + (NumHex[i] - 87) * Base;
            Base = Base * 16;
        }
    }
    return Rem; 
}

int main()
{
    int Casos;
    long long NumInt, NumDec,
                NHexDec, NumBinHexa;
    string Num;
    char Tipo[4];    
    cin >> Casos;
    for(int Case = 0; Case < Casos; Case++)
    {
        NumDec = 0;
        Num = "";
        NumInt = 0;
        cin >> Num >> Tipo;
        for(long long k = Num.size() - 1, l = 1; k >= 0; k--, l = l * 10)
        {
            NumInt = NumInt + (Num[k] - 48) * l;
        }
        cout << "Case " << Case + 1 << ":" << '\n';
        if(strcmp(Tipo, "dec") == 0)
        {
            string NumDecHex = ConvertDecToHex(NumInt);
            cout << NumDecHex << " hex" << '\n';
            long long BinNum[33];
            ConvertDecToBin(BinNum, NumInt);
            for(j = i - 1; j >= 0; j--)
            {
                cout << BinNum[j];
            } 
            cout << " bin" << "\n";
        }
        else if(strcmp(Tipo, "bin") == 0)
        {
            NumDec = ConvertBinToDec(Num);
            if (NumDec < 0)
                NumDec = NumDec * -1;
            cout << NumDec << " dec" << '\n';
            string NumBinHex = ConvertDecToHex(NumDec);
            cout << NumBinHex << " hex" << '\n';
        }
        else if(strcmp(Tipo, "hex") == 0)
        {
            NHexDec = ConvertHexToDec(Num);
            if (NHexDec < 0)
                NHexDec = NHexDec * -1;
            cout << NHexDec << " dec" << '\n';
            long long int HexBinNum[33];
            ConvertDecToBin(HexBinNum, NHexDec);
            for(j = i - 1; j >= 0; j--)
            {
                cout << HexBinNum[j];
            }
            cout << " bin" << "\n";
        }
        cout << '\n';
    }
}