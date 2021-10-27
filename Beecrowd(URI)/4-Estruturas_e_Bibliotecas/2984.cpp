#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

int main() 
{
	int Sum = 0;
	string Str;
	queue< char > myqueue;
	cin >> Str;
	for	(int i = 0; i < Str.size(); i++)
		myqueue.push(Str[i]);
	while(!myqueue.empty())
	{
		if	(myqueue.front() == '(')
			Sum++;
		else
			if	(myqueue.front() == ')' && Sum > 0)
				Sum--;
		myqueue.pop();
	}
	if	(Sum > 0)
		cout << "Ainda temos " << Sum
			 << " assunto(s) pendente(s)!" << '\n';
	else
		cout << "Partiu RU!" << '\n';
}