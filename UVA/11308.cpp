#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <stack>
#include <list>
#include <limits.h>
#include <string.h>
#include <iomanip>

using namespace std;

#define pi 3.141592653589793
#define eulerconstant 0.577215664901532
#define sz 500
#define f first
#define s second
#define inf 1000000000
#define inf64 1000000000000000000

typedef pair<int, int> ii;
typedef pair<char, int> ci;
typedef pair<string, int> si;
typedef vector< int > vi;
typedef vector< char > vc;
typedef vector<pair<int, int>> vii;
typedef vector<pair< int, pair<int, int>>> viii;
typedef vector<vector<int>> vvi;
typedef long long ll;

int Visit[sz];
vii AdjList[sz];

int x[] = {0,-1,0,1}, y[] = {-1,0,1,0};

bool Comp(pair<string, long> A, pair<string, long> B)
{
	if (A.s > B.s)
		return false;
	if (A.s < B.s)
		return true;
	return (A.f < B.f);
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int T; scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		map<string, int> myMap;
		vector<pair<string, long>> myVet;
		string Str, Ing;
		long C;
		cin.ignore();
		getline(cin, Str);
		int M, N;
		long B;
		cin >> M >> N >> B;
		for (int j = 0; j < M; j++)
		{
			string Ing;
			int C;
			cin >> Ing >> C;
			myMap.insert(pair<string, int>(Ing, C));
		}
		for (int j = 0; j < N; j++)
		{
			string Re;
			cin.ignore();
			getline(cin, Re);
			long Tot = 0, X; cin >> X;
			for (int k = 0; k < X; k++)
			{
				cin >> Ing >> C;
				Tot += myMap[Ing] * C;
			}
			if (Tot <= B)
				myVet.push_back(si(Re, Tot));
		}
		for (int j = 0; j < Str.length(); j++)
		{
			if (Str[j] >= 'a' && Str[j] <= 'z')
				Str[j] = Str[j] - 32;
		}
		cout << Str << '\n';
		if (myVet.size() == 0)
			cout << "Too expensive!\n\n";
		else
		{
			sort(myVet.begin(), myVet.end(), Comp);
			for (int j = 0; j < myVet.size(); j++)
				cout << myVet[j].f << '\n';
			cout << '\n';
		}
	}
}