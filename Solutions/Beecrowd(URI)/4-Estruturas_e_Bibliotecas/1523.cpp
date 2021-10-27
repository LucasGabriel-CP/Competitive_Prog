#include <iostream>
#include <stack>
#include <utility>

using namespace std;

int main()
{
    int N, K, C, S, Qntd;
    bool Valid;
    while(cin >> N >> K && N && K)
    {
        Qntd = 1;
        Valid = true;
        cin >> C >> S;
        stack< pair<int,int> > Estac;
        pair <int,int> Aux;
        Estac.push(make_pair(C,S));
        
        for (int i = 1; i < N; i++)
        {
            cin >> C >> S;
            if	(Estac.top().second > C && Estac.top().second < S || Qntd > K)
                Valid = false;
            while(!Estac.empty() && Estac.top().second <= C && Valid)
                {
                    Estac.pop();
                    Qntd--;
                }
            Qntd++;
            Estac.push(make_pair(C,S));
        }
        
        Aux = Estac.top();
        Estac.pop();
        while(!Estac.empty() && Valid)
        {
            if  (Aux.second > Estac.top().second || Estac.top().second < Aux.first)
                Valid = false;

            Aux = Estac.top();
            Estac.pop();
        }
        if  (!Valid || Qntd > K)
            cout << "Nao\n";
        else
            cout << "Sim\n";
    }
}