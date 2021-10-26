#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

struct Medalha
{
	int G, P, B;
};

bool Comp(pair<string, Medalha> A, pair<string, Medalha> B)
{
	if ((A.s).G < (B.s).G)
		return false;
	if ((A.s).G > (B.s).G)
		return true;
	if ((A.s).P < (B.s).P)
		return false;
	if ((A.s).P > (B.s).P)
		return true;
	if ((A.s).B < (B.s).B)
		return false;
	if ((A.s).B > (B.s).B)
		return true;
	return (A.f < B.f);
}

int main()
{
	string Moda;
	map<string, Medalha> myMap;
	set< string > mySet;
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	fflush(stdin);
	while (getline(cin, Moda))
	{
		string Pais;
		getline(cin, Pais);
		myMap[Pais].G++;
		getline(cin, Pais);
		myMap[Pais].P++;
		getline(cin, Pais);
		myMap[Pais].B++;
	}

	vector<pair<string, Medalha>> Vet;
	for (map<string, Medalha>::iterator it = myMap.begin(); it != myMap.end(); ++it)
		Vet.push_back({ it->f, {it->s.G, it->s.P, it->s.B} });

	stable_sort(Vet.begin(), Vet.end(), Comp);
	cout << "Quadro de Medalhas\n";
	for (pair<string, Medalha> i : Vet)
		cout << i.f << ' ' << i.s.G << ' ' << i.s.P << ' ' << i.s.B << '\n';
}