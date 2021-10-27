#include <iostream>
#include <string>

using namespace std;

int main()
{
	int QntLet, PosiLet;
	string Frase;
	char Lets[26];
	while(cin >> Lets)
    {
        cin >> QntLet;
        Frase = "";
        for(int i = 0; i < QntLet; i++)
        {
            cin >> PosiLet;
            Frase = Frase + Lets[PosiLet - 1];
        }
        cout << Frase << '\n';
    }
}