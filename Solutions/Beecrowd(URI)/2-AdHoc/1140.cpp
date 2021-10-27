#include <bits/stdc++.h>

using namespace std;

int main()
{
	string Pri;
	getline(cin, Pri);
	while (Pri != "*")
	{
		char Valid = Pri[0];
		bool ok = true;
		int Tam = (int)Pri.size();
		for (int i = 1; i < Tam && ok; i++)
		{
			if (Pri[i] == ' ' && i < 1 + Tam)
				if (Pri[i + 1] != Valid && !(Pri[i + 1] == Valid - 32 || Pri[i + 1] == Valid + 32))
					ok = false;
		}
		if (ok)
			cout << "Y\n";
		else
			cout << "N\n";
		getline(cin, Pri);
	}
}