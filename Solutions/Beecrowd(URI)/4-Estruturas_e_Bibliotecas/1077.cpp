#include<bits/stdc++.h>

using namespace std;

int Priori(char Carac)
{
    if (Carac == '+' || Carac == '-')
        return 3;
    if (Carac == '*' || Carac == '/')
        return 2;
    if (Carac == '^')
        return 1;
    return 4;
}

int main()
{
    int Case;
    string Str;
    cin >> Case;
    for (int i = 0; i < Case; i++)
    {
        stack< char > Cesto;
        cin >> Str;
        for (int j = 0; j < Str.size(); j++)
        {
            if (Str[j] == '+' || Str[j] == '-' || Str[j] == '*'
                || Str[j] == '/' || Str[j] == '^')
            {
                while (!Cesto.empty() && Priori(Str[j]) >= Priori(Cesto.top()))
                {
                    cout << Cesto.top();
                    Cesto.pop();
                }
                Cesto.push(Str[j]);
            }
            else
                if (Str[j] == '(')
                    Cesto.push(Str[j]);
                else
                    if (!Cesto.empty() && Str[j] == ')')
                    {
                        while (!Cesto.empty() && Cesto.top() != '(')
                        {
                            if (Cesto.top() != ' ')
                                cout << Cesto.top();
                            Cesto.pop();
                        }
                        if (!Cesto.empty())
                            Cesto.pop();
                    }
                    else
                        if (Str[j] != ' ')
                            cout << Str[j];
        }

        while (!Cesto.empty())
        {
            if (Cesto.top() != ' ')
                cout << Cesto.top();
            Cesto.pop();
        }
        cout << '\n';
    }
}