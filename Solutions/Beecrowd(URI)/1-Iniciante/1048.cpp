#include <iostream>
#include <iomanip>

using namespace std;

int main () 
{
    double Salario, NovoSalario, Reajuste;
    cin >> Salario;
    cout << fixed << setprecision(2);
    if (Salario <= 400.00) 
    {
        Reajuste = (Salario / 100) * 15;
        NovoSalario = Salario + Reajuste;
        cout << "Novo salario: " << NovoSalario << "\n"
            << "Reajuste ganho: " << Reajuste << "\n"
            << "Em percentual: 15 %" << "\n";
    }
    else if (Salario >= 400.01 && Salario <= 800.00) 
    {
        Reajuste = (Salario / 100) * 12;
        NovoSalario = Salario + Reajuste;
        cout << "Novo salario: " << NovoSalario << "\n"
            << "Reajuste ganho: " << Reajuste << "\n"
            << "Em percentual: 12 %" << "\n";
    }
    else if (Salario >= 800.01 && Salario <= 1200.00) 
    {
        Reajuste = (Salario / 100) * 10;
        NovoSalario = Salario + Reajuste;
        cout << "Novo salario: " << NovoSalario << "\n"
            << "Reajuste ganho: " << Reajuste << "\n"
            << "Em percentual: 10 %" << "\n";
    }
    else if (Salario >= 1200.01 && Salario <= 2000.00) 
    {
        Reajuste = (Salario / 100) * 7;
        NovoSalario = Salario + Reajuste;
        cout << "Novo salario: " << NovoSalario << "\n"
            << "Reajuste ganho: " << Reajuste << "\n"
            << "Em percentual: 7 %" << "\n";
    }
    else if (Salario > 2000.00) 
    {
        Reajuste = (Salario / 100) * 4;
        NovoSalario = Salario + Reajuste;
        cout << "Novo salario: " << NovoSalario << "\n"
            << "Reajuste ganho: " << Reajuste << "\n"
            << "Em percentual: 4 %" << "\n";
    }
}