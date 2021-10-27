#include <iostream>

using namespace std;
string VerificarRoubo();

int  R, A;

int main()
{
    int P, J1, J2, Resultado;
    string Result = "";
    cin >> P >> J1 >> J2
    >> R >> A;

    if (R == 0 && A == 0)
    {
        Resultado = (J1 + J2) % 2;
        if (P == 1)
            switch (Resultado)
            {
                case 0: Result = "Jogador 1 ganha!";	break;
                case 1: Result = "Jogador 2 ganha!";
            }
        else if (P == 0)
            switch (Resultado)
            {
                case 0: Result = "Jogador 2 ganha!";	break;
                case 1: Result = "Jogador 1 ganha!";
            }
    }
    else
       Result = VerificarRoubo();
    cout << Result << '\n';
}

string VerificarRoubo()
{
    string Str = "";
    if (R == 1 && A == 1)
        Str = "Jogador 2 ganha!";
    else if (R == 1 && A == 0)
        Str = "Jogador 1 ganha!";
    else if (R == 0 && A == 1)
        Str = "Jogador 1 ganha!";
    return Str;
}