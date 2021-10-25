#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    int Abre, Fecha;
    string Exp;
    Exp = string(2, 'a');

    while(cin >> Exp)
    {
        Abre = Fecha = 0;
        bool Valid = true;
        if (Exp[0] == ')' || Exp.size() == 1 || Exp[Exp.size() - 1] == '(')
            cout << "incorrect\n";
        else
        {
            stack<char> pilha;
            for (int i = Exp.size() - 1; i >= 0; i--)
            {
                if (Exp[i] == ')')
                {
                    pilha.push(Exp[i]);
                    Abre++;
                }
                if (Exp[i] == '(')
                {
                    pilha.push(Exp[i]);
                    Fecha++;
                }
                if  (Fecha > Abre)
                    Valid = false;
            }
            if  (Valid && Abre == Fecha)
                cout << "correct\n";
            else
                cout << "incorrect\n";
        }
    }
}