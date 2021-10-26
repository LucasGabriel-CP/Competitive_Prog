#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    int M, N;
    long Count, Valor;
    string Dic, Str;
    map< string, int > mymap;

    cin >> M >> N;
    for	(int i = 0; i < M; i++)
    {
        cin >> Dic >> Valor;
        mymap[Dic] = Valor;
    }

    for	(int i = 0; i < N; i++)
    {
        Count = 0;
        cin >> Str;
        while(Str != ".")
        {
            if	(mymap.count(Str) != 0)
                Count += mymap[Str];
            cin >> Str;
        }
        cout << Count << '\n';
    }
}