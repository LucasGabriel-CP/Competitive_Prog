#include <iostream>

using namespace std;

int Proced(int N, int Count)
{
	if  (N == 1)
		return Count - 1;
	Count = Proced(N - 1, 2 * Count);
}

int main()
{
	int i = 1, N, Result = 0;
	cin >> N;
	while (N != 0)
	{
		Result = Proced(N, 2);
		cout << "Teste " << i << '\n'
			 << Result << "\n\n";
		i++;
		cin >> N;
	}
}