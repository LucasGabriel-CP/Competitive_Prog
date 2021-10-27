#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int Num[3];
    while(cin >> Num[0] >> Num[1] >> Num[2])
    {
        sort(Num, Num + 3);
        bool tururu = false;
        if(pow(Num[2], 2) == pow(Num[1], 2) + pow(Num[0], 2))
        {
            for(int i = Num[0]; i > 1; i--)
            {
                if(Num[0] % i == 0 && Num[1] % i == 0 && Num[2] % i == 0)
                    tururu = true;
            }
            if(tururu == false)
                cout << "tripla pitagorica primitiva" << '\n';
            else
                cout << "tripla pitagorica" << '\n';
        }
        else
            cout << "tripla" << '\n';
    }
}