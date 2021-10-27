#include <iostream>
#include <string>

using namespace std;
string ConvertHexa(long int Dec);

int main()
{
    long int NDec;
    string Result;
    cin >> NDec;
    Result = ConvertHexa(NDec);
    cout << Result << '\n';
}

string ConvertHexa(long int Dec)
{
    string Result = "";
    long int Rem;
    while(Dec > 0)
        {
            Rem = Dec % 16;
            if (Rem > 9)
            {
                switch(Rem)
                {
                    case 10: Result = "A" + Result; break;
                    case 11: Result = "B" + Result; break;
                    case 12: Result = "C" + Result; break;
                    case 13: Result = "D" + Result; break;
                    case 14: Result = "E" + Result; break;
                    case 15: Result = "F" + Result; break;
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