#include <iostream>

using namespace std;

int main()
{	
	long int N[1000], i, j;
	cin >> N[0];
	i = 1;
	while(cin >> N[i] && N[i] > 0)
	{
	    i++;
	}
	for(j = 1; j < i && N[j] > N[j - 1]; j++);
	    cout << N[j - 1] + 1 << '\n';
}