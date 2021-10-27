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
#include <assert.h>
#include <bitset>

using namespace std;

#define pi 3.141592653589793
#define eulerconstant 0.577215664901532
#define sz 10050
#define f first
#define s second
#define inf ~(1<<31) - 1
#define inf64 1000000000000000000

typedef pair<int, int> ii;
typedef pair< int, pair<int, int>> iii;
typedef pair<char, int> ci;
typedef pair<string, int> si;
typedef vector< int > vi;
typedef vector< long long > vll;
typedef vector< char > vc;
typedef vector<pair<int, int>> vii;
typedef vector<pair< int, pair<int, int>>> viii;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvf;
typedef long long ll;

string StrIn;
string StrOut;
int N;

void buildPath(string CurP, stack<char> S, char NOp, int In, int Out, int Pu, int Po)
{
	CurP += NOp;
	if (NOp == 'i')
	{
		Pu++;
		S.push(StrIn[In++]);
	}
	else
	{
		if (S.empty()) return;
		Po++;
		char Temp = S.top();	S.pop();
		if (Temp != StrOut[Out]) return;
		Out++;
	}
	if ((int)CurP.size() == 2 * N)
	{
		for (int i = 0; i < (int)CurP.size() - 1; ++i)
			cout << CurP[i] << ' ';
		cout << CurP[CurP.size() - 1] << '\n';
	}
	else
	{
		if (Pu < N)
			buildPath(CurP, S, 'i', In, Out, Pu, Po);
		if (Po < N)
			buildPath(CurP, S, 'o', In, Out, Pu, Po);
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	while (cin >> StrIn)
	{
		N = (int)StrIn.size();
		cin >> StrOut;
		stack<char> S;
		cout << "[\n";
		if (N == (int)StrOut.size())
			buildPath("", S, 'i', 0, 0, 0, 0);
		cout << "]\n";
	}

	return 0;
}