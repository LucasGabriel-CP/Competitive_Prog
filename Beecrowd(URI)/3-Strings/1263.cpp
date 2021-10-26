#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

int main()
{
	string Str;
	while (getline(cin, Str))
	{
		bool ok = false;
		char Aux;
		int Ans = 0;
		forn(i, Str.size())
		{
			if (!i)
			{
				Aux = Str[i] < 96 ? char(Str[i] + 32) : Str[i];
			}
			if (i < Str.size() - 1 && Str[i] == ' ')
			{
				if (Str[i + 1] == Aux || char(Str[i + 1] + 32) == Aux)
					ok = true;
				else
					if (ok)
					{
						Ans++;
						ok = false;
					}
				Aux = Str[i + 1] < 96 ? char(Str[i + 1] + 32) : Str[i + 1];
			}
		}
		if (ok) Ans++;
		cout << Ans << '\n';
	}

	return 0;
}