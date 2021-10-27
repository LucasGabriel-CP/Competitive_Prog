#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    int N, Aux;
    string Vag, Seq;

    while(cin >> N && N)
    {
        stack<char> Estacao;
        Vag = string(N, 'a');
        Seq = string(N, 'a');
        
        for (int i = 0; i < N; i++)
            cin >> Vag[i];
            
        for (int i = 0; i < N; i++)
            cin >> Seq[i];
        Aux = 0;
        for (int i = 0; i < N; i++)
        {
            Estacao.push(Vag[i]);
            cout << "I";
            while(!Estacao.empty() && Estacao.top() == Seq[Aux])
            {
                Estacao.pop();
                Aux++;
                cout << "R";
            }
        }
        if  (Aux != N)
            cout << " Impossible";
        cout << '\n';
    }
}