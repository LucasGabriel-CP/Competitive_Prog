#include <bits/stdc++.h>

using namespace std;

int main()
{
    char Str[210];
    set<string> mySet;
    string Pala;
    while (scanf("%s", Str) != EOF)
    {
        Pala = "";
        for (int i = 0; Str[i] != '\0'; i++)
        {
            if (Str[i] >= 'A' && Str[i] <= 'Z')
                Pala += Str[i] + 32;
            else
                if (Str[i] >= 'a' && Str[i] <= 'z')
                    Pala += Str[i];
                else
                    if (Pala != "")
                    {
                        mySet.insert(Pala);
                        Pala = "";
                    }
        }
        if (Pala != "")
            mySet.insert(Pala);
    }
    for (set< string >::iterator it = mySet.begin(); it != mySet.end(); ++it)
        cout << *it << '\n';
}