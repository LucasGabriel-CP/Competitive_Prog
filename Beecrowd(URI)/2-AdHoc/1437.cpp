#include <iostream>

using namespace std;

int main()
{
    int QntComand, i;
    char Posi;
    cin >> QntComand;
    while (QntComand != 0)
    {
        char Comando[QntComand];
        Posi = 'N';
        for (i = 0; i < QntComand; i++)
        {
            cin >> Comando[i];
        }
        for (i = 0; i < QntComand; i++)
        {
            if (Posi == 'N')
            {
                Posi = Comando[i] == 'E' ? 'O' : 'L';
            }
            else if (Posi == 'L')
            {
                Posi = Comando[i] == 'E' ? 'N' : 'S';
            }
            else if (Posi == 'O')
            {
                Posi = Comando[i] == 'E' ? 'S' : 'N';
            }
            else
            {
                Posi = Comando[i] == 'E' ? 'L' : 'O';
            }
        }
        cout << Posi << '\n';
        cin >> QntComand;
    }
}