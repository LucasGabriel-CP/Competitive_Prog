#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	char N;
	string Str;
	while (cin >> N >> Str, N != '0' || Str != "0")
	{
		string Aux = "";
		char Zeros = '1';
		for (int i = 0; i < Str.size(); i++)
		{
			if (Str[i] == '0' && Zeros == '1') continue;
			if (Str[i] != N)
			{
				Aux += Str[i];
				Zeros = '0';
			}
		}
		Aux.size() ? cout << Aux << '\n'
			: cout << "0\n";
	}

	return 0;
}