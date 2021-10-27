#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    while (N != 2002)
    {
        cout << "Senha Invalida" << '\n';
        cin >> N;
    }
    cout << "Acesso Permitido" << '\n';
}