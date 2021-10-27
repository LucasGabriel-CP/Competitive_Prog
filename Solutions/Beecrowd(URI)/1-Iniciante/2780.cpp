#include <iostream>

using namespace std;

int main()
{
	int Dist;
	cin >> Dist;
	if(Dist < 801)
		cout << "1" << '\n';
	else if (Dist < 1401)
		cout << "2" << '\n';
	else
		cout << "3" << '\n';
}