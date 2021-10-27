#include <iostream>

using namespace std;

int main()
{
	int N, Altura, AMax, AMin, Visitante;
	while (cin >> N)
    {
        cin >> AMin >> AMax;
        Visitante = 0;
        for (int i = 0; i < N; i++)
        {
            cin >> Altura;
            if (Altura >= AMin && Altura <= AMax)
            Visitante++;
        }
        cout << Visitante << '\n';
    }
}