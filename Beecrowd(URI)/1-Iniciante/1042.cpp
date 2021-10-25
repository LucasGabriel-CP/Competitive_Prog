#include <iostream>

using namespace std;

int main()
{
    int A, B, C;
    cin >> A >> B >> C;
    if (A < B && A < C) 
    {
        if (B < C) 
            cout << A << "\n" << B << "\n" << C << "\n\n";
        else
            if(C < B) 
                cout << A << "\n" << C << "\n" << B << "\n\n";
    }
    else if (B < A && B < C) 
    {
        if (A < C) 
            cout << B << "\n" << A << "\n" << C << "\n\n";
        else 
            if(C < A) 
                cout << B << "\n" << C << "\n" << A << "\n\n";
    }
    else if (C < A && C < B)
    {
        if (A < B) 
            cout << C << "\n" << A << "\n" << B << "\n\n";
        else
            if(B < A)
                cout << C << "\n" << B << "\n" << A << "\n\n";
    }
    cout << A <<"\n"<< B << "\n" << C << "\n";
}