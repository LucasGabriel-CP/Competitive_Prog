#include <iostream>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

int main() 
{
	int N;
	string Lista, Str;
	
	cin >> N;
	cin.ignore();
	for	(int i = 0; i < N; i++)
	{
		set< string > myset;
		Str = "";
		getline(cin, Lista);
		for	(int j = 0; j < Lista.size(); j++)
		{
			if	(Lista[j] != ' ')
				Str += Lista[j];
			else
			{
				myset.insert(Str);
				Str = "";
			}
		}
		myset.insert(Str);
		set< string >::iterator it = myset.begin();
		cout << *it;
		++it;
		while(it != myset.end())
		{
			cout << " " << *it;
			++it;
		}
		cout << '\n';
	}
}