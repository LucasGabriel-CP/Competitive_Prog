#include <iostream>
#include <deque>

using namespace std;

int main()
{
    int N, Num;
    string Nome;
    while(cin >> N && N)
    {
        Nome = string(1,'a');
        deque < pair<string,int> > Roda;
        int Changes;
        cin >> Nome >> Num;
        Roda.push_back(make_pair(Nome,Num));
        Changes = Roda.front().second;
        for (int i = 0; i < N - 1; i++)
        {
            cin >> Nome >> Num;
            Roda.push_back(make_pair(Nome,Num));
        }
        
        if	(Changes % 2 != 0)
        {
            Roda.push_back(Roda.front());
            Roda.pop_front();
        }
        while(Roda.size() > 1)
        {
            if	(Changes % 2 == 0)
            {
                for (int i = 0; i < Changes; i++)
                {
                    Roda.push_front(Roda.back());
                    Roda.pop_back();
                }
                Changes = Roda.front().second;
                Roda.pop_front();
            }
            else
            {
                for (int i = 0; i < Changes; i++)
                {
                    Roda.push_back(Roda.front());
                    Roda.pop_front();
                }
                Changes = Roda.back().second;
                Roda.pop_back();
            }
        }
        cout << "Vencedor(a): " 
                << Roda.front().first << '\n';
    }
}