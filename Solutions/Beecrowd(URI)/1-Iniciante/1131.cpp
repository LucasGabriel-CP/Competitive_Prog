#include <iostream>

using namespace std;

int main ()
{
    int GolInter, GolGre, Inter	= 0, Gremio = 0,
        Empate = 0, Grenal = 0, Opcao;
    do
    {
        cin >> GolInter >> GolGre;
        Grenal++;
        if (GolInter > GolGre)
            Inter++;
        else if (GolInter < GolGre)
            Gremio++;
        else
            Empate++;
        cout << "Novo grenal (1-sim 2-nao)" << '\n';
        cin >> Opcao;
    } while (Opcao == 1);
    cout << Grenal << " grenais" << '\n'
        << "Inter:" << Inter << '\n'
        << "Gremio:" << Gremio << '\n'
        << "Empates:" << Empate <<'\n';
    if (Inter > Gremio)
        cout << "Inter venceu mais" << '\n';
    else if (Inter < Gremio)
        cout << "Gremio venceu mais" << '\n';
    else
       cout << "Nao houve vencedor" << '\n';
}