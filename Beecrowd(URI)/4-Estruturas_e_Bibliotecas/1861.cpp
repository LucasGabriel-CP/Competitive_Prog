#include <bits/stdc++.h>

using namespace std;

int main()
{
    string Assas, Morto;
    map< string, int > Count;
    set< string > Mortos;
    while(cin >> Assas >> Morto)
    {
        Count[Assas]++;
        Mortos.insert(Morto);
    }
    cout << "HALL OF MURDERERS" << '\n';
    for	(auto it:Count)
    {
        if	(!Mortos.count(it.first))
            cout << it.first << " " << it.second << '\n';
    }
}