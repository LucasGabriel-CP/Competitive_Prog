#include <iostream>

using namespace std;

int Call;

int Fibonacci(int N)
{
    int Fib;
    Call = Call + 1;
    if  (N == 0)
        Fib = 0;
    else
        {
            if  (N == 1)
                Fib = 1;
            else
                Fib = Fibonacci(N - 1) + Fibonacci(N - 2);
        }
    return Fib;
}

int main()
{
    int Case, Num, Result;
    cin >> Case;
    for (int i = 0; i < Case; i++)
    {
        Call = -1;
        cin >> Num;
        Result = Fibonacci(Num);
        cout << "fib(" << Num << ") = " 
                << Call << " calls = " << Result << '\n';
    }
}