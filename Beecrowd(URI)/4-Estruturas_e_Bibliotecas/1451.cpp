#include <bits/stdc++.h>

using namespace std;

int main()
{
    string Str;
    while (cin >> Str)
    {
        bool Tururu = true;
        list<char> myList;
        list<char> Aux;
        long Tam = (long)Str.size();
        for (long i = 0; i < Tam; i++)
        {
            if (Str[i] == '[')
            {
                while (!myList.empty())
                {
                    Aux.push_front(myList.back());
                    myList.pop_back();
                }
                Tururu = false;
            }
            else
                if (Str[i] == ']')
                    Tururu = true;
                else
                    if (Tururu)
                        Aux.push_back(Str[i]);
                    else
                        myList.push_back(Str[i]);
        }
        while (!myList.empty())
        {
            cout << myList.front();
            myList.pop_front();
        }
        while (!Aux.empty())
        {
            cout << Aux.front();
            Aux.pop_front();
        }
        cout << '\n';
    }
}