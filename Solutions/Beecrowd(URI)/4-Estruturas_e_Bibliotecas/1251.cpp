#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <string>

using namespace std;
typedef pair<int,int> ii;

bool Ordena(ii a, ii b)
{
    if	(a.second < b.second)
        return 1;
    if	(a.second == b.second)
    {
        if	(a.first > b.first)
            return 1;
    }
    return 0;
}

int main()
{
    int Aux, N;
    bool Pula = false;
    string Str;

    while(cin >> Str)
    {
        if	(Pula)
            cout << '\n';
        Pula = true;
        vector< ii > Ans;
        map< char, int > myMap;
        myMap[Str[0]]++;
        for	(int i = 1; i < Str.size(); i++)
        {
            myMap[Str[i]]++;
        }
        
        for	(map<char,int>::iterator it = myMap.begin(); it != myMap.end(); ++it)
        {
            Ans.push_back(ii((int)it->first, it->second));

        }
        
        sort(Ans.begin(), Ans.end(), Ordena);
        
        for	(int i = 0; i < Ans.size(); i++)
            cout << Ans[i].first << " " << Ans[i].second << '\n';
        
    }
}