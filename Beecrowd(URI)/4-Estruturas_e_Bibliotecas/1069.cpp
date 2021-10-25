#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    int Case, Dimamante, Rabo;
    string Teste;	
    cin >> Case;
    for (int i = 0; i < Case; i++)
    {
        stack<char> pilha;
        Dimamante = Rabo = 0;
        Teste = string(1,'a');

        cin >> Teste;
        for (int j = 0; j < Teste.size(); j++)
            if (Teste[j] == '<' || Teste[j] == '>')
                pilha.push(Teste[j]);
        while(!pilha.empty())
        {
            if  (pilha.top() == '>')
                Rabo++;
            else
                if  (pilha.top() == '<' && Rabo > 0)
                {
                    Dimamante++;
                    Rabo--;
                }
            pilha.pop();
        }
        cout << Dimamante << '\n';
    }
}