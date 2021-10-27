#include <iostream>
#include <string.h>
#include <map>

using namespace std;

int main() 
{
	int N, M;
	string Lingua, Nome, Palavra;
	map< string,string > mymap;

	cin >> N;
	cin.ignore();
	for	(int i = 0; i < N; i++)
	{
		getline(cin, Lingua);
		getline(cin, Palavra);
		mymap[Lingua] = Palavra;
	}
	cin >> M;
	cin.ignore();
	for	(int i = 0; i < M; i++)
	{
		getline(cin, Nome);
		getline(cin, Lingua);
		cout << Nome << '\n';
		cout << mymap[Lingua] << "\n\n";
	}
}