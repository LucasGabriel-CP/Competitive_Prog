#include <bits/stdc++.h>

using namespace std;

int main()
{
	string Str1, Str2, Str3;
	getline(cin, Str1);
	scanf("");
	getline(cin, Str2);
	scanf("");
	cin >> Str3;
	if (Str3 == "nao")
	{
		cout << Str1 << ' ' << Str2 << '\n';
		return 0;
	}
	bool ok = false;
	string Aux = "";
	for (int i = 0; i < (int)Str1.size() - 1; i++)
	{
		if (Str1[i] == ' ')
		{
			if (Aux == Str3)
			{
				cout << Str2 << ' ' << Aux << ' ';
				ok = true;
			}
			else
				cout << Aux << ' ';
			Aux = "";
			continue;
		}
		Aux += Str1[i];
	}
	if (!ok)
		cout << Str2 << ' ';
	cout << Aux + Str1.back() << '\n';

	return 0;
}