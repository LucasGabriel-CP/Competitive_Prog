#include <iostream>
#include <string>

using namespace std;

int ACM(int Num, int Fat)
{
	if  (Num == 1)
		return Fat;
	else
	{
		Num--;
		return ACM(Num, Fat * Num);
	}
}

int main()
{
	string Num;
	long N;
	int Result;
	cin >> Num;
	while (Num != "0")
	{
		Result = 0;
		for (int i = 0, j = Num.size(); i < Num.size(); i++, j--)
		{
			N = (int)Num[i] - 48;
			Result += N * ACM(j, j);
		}
		cout << Result << '\n';
		cin >> Num;
	}
}