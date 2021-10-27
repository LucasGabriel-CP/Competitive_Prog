#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main() 
{
	int N, M;
	string Str;
	stack< string > mystack;
	vector< string > VetD;
	vector< string > VetV;
	cin >> N >> M;
	for	(int i = 0; i < N; i++)
	{
		for	(int j = 0; j < M; j++)
		{
			cin >> Str;
			if	(Str[Str.size() - 1] == 'V')
				VetV.push_back(Str);
			else
				VetD.push_back(Str);
		}
	}
	
	if	(!VetV.empty())
		sort(VetV.begin(),VetV.end());
	if	(!VetD.empty())
		sort(VetD.begin(),VetD.end());	
	
	for	(int i = 0; i < VetV.size(); i++)
		mystack.push(VetV[i]);
	while(!mystack.empty())
	{
		cout << mystack.top() << '\n';
		mystack.pop();
	}
	
	for	(int i = 0; i < VetD.size(); i++)
		mystack.push(VetD[i]);
	while(!mystack.empty())
	{
		cout << mystack.top() << '\n';
		mystack.pop();
	}
}