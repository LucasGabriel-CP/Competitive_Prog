#include <iostream>

using namespace std;

int main()
{
    int Casos, Time1[2], Time2[2],
    TotTime1, TotTime2;
    char X;
    string Resultado;
    cin >> Casos;
    for (int i = 0; i < Casos; i++)
    {
        cin >> Time1[0] >> X >> Time2[0]
            >> Time2[1] >> X >> Time1[1];
        TotTime1 = Time1[0] + Time1[1];
        TotTime2 = Time2[0] + Time2[1];
        if (TotTime1 > TotTime2)
        Resultado = "Time 1";
        else if (TotTime2 > TotTime1)
        Resultado = "Time 2";
        else
        {
            if (Time1[1] > Time2[0])
                Resultado = "Time 1";
            else if (Time1[1] < Time2[0])
                Resultado = "Time 2";
            else
                Resultado = "Penaltis";
        }
        cout << Resultado << '\n';
    }
}