#include <iostream>

using namespace std;

int MDC(int Num1, int Num2)
{
    if (Num1 % Num2 == 0)
        return Num2;
    return MDC(Num2, Num1 % Num2);
}

int main()
{
    int Case, F2, F1,
        Result, Valid = 0;
    cin >> Case;
    while (Valid < Case)
    {
        cin >> F1 >> F2;
        if (F2 > F1)
            swap(F1, F2);
        Result = MDC(F1, F2);
        cout << Result << '\n';
        Valid++;
    }
}