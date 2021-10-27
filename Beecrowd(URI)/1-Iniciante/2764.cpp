#include <iostream>

using namespace std;

int main()
{
	char Data[9];
	cin >> Data;
	swap(Data[0],Data[3]);
	swap(Data[1],Data[4]);
	cout << Data << '\n';
	swap(Data[0],Data[6]);
	swap(Data[1],Data[7]);
	swap(Data[3],Data[6]);
	swap(Data[4],Data[7]);	
	cout << Data << '\n';
	swap(Data[0],Data[6]);
	swap(Data[1],Data[7]);	
	cout << Data[0] << Data[1] << "-"
		 << Data[3] << Data[4] << "-"
		 << Data[6] << Data[7] << '\n';
}