#include <iostream>

using namespace std;

int main()
{
	int A, B, C, D,
		Tururu1, Tururu2, Tururu3;
	cin >> A >> B >> C >> D;
	Tururu1 = B - A;
	Tururu2 = D - C;
	if (Tururu1 - Tururu2 < 0)
		Tururu3 = (Tururu1 - Tururu2) * - 1;
	else
		Tururu3 = Tururu1 - Tururu2;		
	cout << Tururu3 << '\n';
}