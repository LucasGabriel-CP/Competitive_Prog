#include <bits/stdc++.h>

using namespace std;

typedef pair<char, int> ci;

int main()
{
	int Ans, Count, N, Tam;
	string Str;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		vector< ci > Vet;

		cin >> Tam >> Str;
		Ans = 0;
		if (Tam > 2)
		{
			if (Str[0] > Str[Tam - 1])
			{
				swap(Str[0], Str[Tam - 1]);
				Ans++;
			}
			for (int i = 0; i < Tam - 1; i++)
			{
				if (Str[i] > Str[i + 1])
				{
					Vet.push_back(ci(Str[i + 1], i + 1));
				}
				if (Str[i] == Str[i + 1])
					Ans = 5000;
			}
			if (Vet.size() > 2)
				Ans = 5000;
			else
				if (Vet.size() == 2)
				{
					swap(Str[Vet[0].second], Str[Vet[1].second]);

				}
				else
					if (Vet.size() == 1)
					{
						if (Vet[0].second)
						{
							if (Str[Vet[0].second] < Str[Vet[0].second - 1])
								swap(Str[Vet[0].second - 1], Str[Vet[0].second]);
							else
								swap(Str[Vet[0].second + 1], Str[Vet[0].second]);
						}
						Ans++;
					}
			for (Count = 0; Count < Tam - 1 && Str[Count] < Str[Count + 1]; Count++);
			if (Count != Tam - 1)
				Ans++;
		}
		else
			Ans = 0;
		if (Ans > 1)
			cout << "There aren't the chance.\n";
		else
			cout << "There are the chance.\n";
	}
}