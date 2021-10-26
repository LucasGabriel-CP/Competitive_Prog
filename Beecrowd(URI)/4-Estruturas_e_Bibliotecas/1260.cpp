#include<iostream>
#include<iomanip>
#include<algorithm>
#include<stack>
#include<map>
#include<vector>
#include<string.h>

using namespace std;

int main()
{
    int N, Aux;
    string Str;
    cout << fixed << setprecision(4);
    cin >> N;
    getline(cin, Str);
    cin.ignore();
    for (int i = 0; i < N; i++)
    {
        map< string,float > mymap;
        Aux = 0;

        while(getline(cin, Str) && Str != "\0")
        {
            mymap[Str]++;
            Aux++;
        }

        for(auto it:mymap)
            cout << it.first << " " << it.second * 100.0 / Aux << '\n';
        if	(i < N - 1)
            cout << '\n';
    }
}