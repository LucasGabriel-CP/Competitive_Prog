#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;


int main() 
{
    int N, Win = 0;
    string Aux;
    char Letras;
    stack <string> Frase;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        Aux = "";
        if	(Frase.empty())
            Frase.push("ECAF");
            
        for (int j = 3; j >= 0; j--)
        {
            cin >> Letras;
            Aux = Aux + Letras;
        }
        if	(Aux == Frase.top())
        {
            Win++;
            Frase.pop();
        }
        else
        {
            reverse(Aux.begin(), Aux.end());
            Frase.push(Aux);
        }
    }

    cout << Win << '\n';
}