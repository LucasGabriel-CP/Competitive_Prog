#include <iostream>

using namespace std;
int VerifyNv(int X);

int main()
{
    int QntLes, LesMaior,
    Lesma, Nv;
    while(cin >> QntLes)
    {
        LesMaior = 0;
        for(int i = 0; i < QntLes; i++)
        {
            cin >> Lesma;
            if(Lesma > LesMaior)
            LesMaior = Lesma;
        }
        Nv = VerifyNv(LesMaior);
        cout << Nv << '\n';
    }
}

int VerifyNv(int X)
{
    if(X < 10)
        return 1;
    else if (X < 20)
        return 2;
    else
        return 3;
}