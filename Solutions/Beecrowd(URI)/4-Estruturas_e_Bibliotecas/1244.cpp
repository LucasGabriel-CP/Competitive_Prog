#include <bits/stdc++.h>

using namespace std;

bool comp(string Str1, string Str2)
{
	return Str1.size() > Str2.size();
}

int main()
{
	int N; cin >> N;
	cin.ignore();
	while (N--)
	{
		vector<string> Vet;
		string C, Str = "";
		int tam;
		getline(cin, C);
		stringstream ss(C);
		while (ss >> Str) {
			Vet.push_back(Str);
		}
		stable_sort(Vet.begin(), Vet.end(), comp);
		tam = Vet.size();
		for (int i = 0; i < tam-1; i++)
			cout << Vet[i] << ' ';
		if (tam)
			cout << Vet[tam - 1] << '\n';
	}
}