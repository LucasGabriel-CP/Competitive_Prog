#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	int Aux, N;
	string Pala, Texto;
	map< string, vector<int> > myMap;
	vector< int > Ans;
	vector< string > Dic;
	getline(cin, Texto);
	Pala = "";
	for	(int i = 0, j = 0; i < Texto.size(); i++)
	{
		if	(Texto[i] != ' ')
			Pala += Texto[i];
		else
		{
			myMap[Pala].push_back(i - Pala.size());
			Pala = "";
		}
	}
	myMap[Pala].push_back(Texto.size() - Pala.size());

	cin >> N;
	for	(int i = 0; i < N; i++)
	{
		cin >> Pala;
		Dic.push_back(Pala);
	}
	for	(int i = 0; i < Dic.size(); i++)
	{
		Pala = Dic[i];
		if	(myMap.count(Pala))
		{
			Ans = myMap[Pala];
			cout << Ans[0];
			for	(int j = 1; j < Ans.size(); j++	)
				cout << " " << Ans[j];
			cout << '\n';
		}
		else
			cout << -1 << '\n';
	}
}