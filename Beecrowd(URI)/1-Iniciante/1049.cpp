#include <iostream>
#include <string>

using namespace std;

int main()
{
    string Coluna, Especie, Alimento;
    cin >> Coluna >> Especie >> Alimento;
    if (Coluna == "vertebrado") 
    {
        if (Especie == "ave") 
        {
            if (Alimento == "carnivoro") 
                cout << "aguia" << "\n";
            else if (Alimento == "onivoro") 
                cout << "pomba" << "\n";
        }
        else if (Especie == "mamifero") 
        {
            if (Alimento == "onivoro") 
                cout << "homem" << "\n";
            else if (Alimento == "herbivoro") 
                cout << "vaca" << "\n";
        }
    }
    else if (Coluna == "invertebrado") 
    {
        if (Especie == "inseto") 
        {
            if (Alimento == "hematofago") 
                cout << "pulga" << "\n";
            else if (Alimento == "herbivoro") 
                cout << "lagarta" << "\n";
        }
        else if (Especie == "anelideo") 
        {
            if (Alimento == "hematofago") 
                cout << "sanguessuga" << "\n";
            else if (Alimento == "onivoro") 
                cout << "minhoca" << "\n";
        }
    }	
}