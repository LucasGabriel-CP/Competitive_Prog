#include <iostream>

using namespace std;

int main()
{
	int i, NumBolas;
	long long int SomaBolas = 0;
	string Rena = "";
	for(i = 0; i < 9; i++)
    {
        cin >> NumBolas;
        SomaBolas += NumBolas;
    }
	for(i = 0; SomaBolas > 0; i++, SomaBolas--)
    {
        if(i > 9)
        i = 1;
    }
	if(i > 9)
		i = 1;
	switch (i) 
    {
        case 1: Rena = "Dasher";  break;
        case 2: Rena = "Dancer";  break;
        case 3: Rena = "Prancer"; break;
        case 4: Rena = "Vixen";   break;
        case 5: Rena = "Comet";   break;
        case 6: Rena = "Cupid";   break;
        case 7: Rena = "Donner";  break;
        case 8: Rena = "Blitzen"; break;
        case 9: Rena = "Rudolph";
    }
	cout << Rena << '\n';
}