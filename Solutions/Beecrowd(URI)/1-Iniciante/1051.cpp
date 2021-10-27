#include <iostream>
#include <iomanip>

using namespace std;

int main ()
{
    float salario, Resultado, IR;
    cout << fixed << setprecision (2);
    cin  >> salario;
    if (salario <= 2000.00)
    {
        cout << "Isento" << "\n";
    }
    else if (salario >= 2000.01 && salario <= 3000.00)
    {
        salario = salario - 2000.00;
        Resultado = salario * 0.08;
        cout << "R$ " << Resultado << "\n";
    }
    else if (salario >= 3000.01 && salario <= 4500.00)
    {
        salario = salario - 3000.00;
        IR = salario * 0.18;
        Resultado = IR + 1000.00 * 0.08;
        cout << "R$ " << Resultado << "\n";
    }
    else if (salario > 4500.00)
    {
        salario = salario - 4500.00;
        IR = salario * 0.28;
        Resultado = IR + 1000.00 * 0.08 + 1500.00 * 0.18;
        cout << "R$ " << Resultado << "\n";
    }
}