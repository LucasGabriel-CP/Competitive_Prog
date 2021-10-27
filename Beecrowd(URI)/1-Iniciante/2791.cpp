#include <iostream>

using namespace std;

int main()
{
	int Feij[4], i;
	for (i = 0; i < 4; i++)
    {
        cin >> Feij[i];	 
    }
	for (i = 0; Feij[i] < 1; i++);
	cout << i + 1 << '\n';		
}