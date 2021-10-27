#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int main()
{
    int Ans, Erros, M, N;
    string Aux, Naula, Nome, Norg;

    while(cin >> N && N)
    {
        map< string, string > myMap;
        Ans = 0;
        for	(int i = 0; i < N; i++)
        {
            cin >> Nome >> Norg;
            myMap[Nome] = Norg;
        }
        cin >> M;
        for	(int i = 0; i < M; i++)
        {
            cin >> Nome >> Naula;
            if	(myMap[Nome] != Naula)
            {
                Aux = myMap[Nome];
                Erros = 0;
                for	(int j = 0; j < Naula.size() && Erros <= 1; j++)
                {
                    if	(Naula[j] != Aux[j])
                        Erros++;
                }
                if	(Erros > 1)
                    Ans++;
            }
        }
        cout << Ans << '\n';
    }
}