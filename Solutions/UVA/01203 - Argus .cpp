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
#include <functional>

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
typedef pair<int, string> si;
typedef vector< int > vi;
typedef vector< char > vc;
typedef vector<pair<int, int>> vii;
typedef vector<pair< int, pair<int, int>>> viii;
typedef vector<vector<int>> vvi;
typedef long long ll;

bool myComp(ii a, ii b)
{
	if (a.f > b.f)
		return true;
	if (a.f < b.f)
		return false;
	return a.s > b.s;
}

int x[] = {0,-1,0,1}, y[] = {-1,0,1,0};

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	vii myVet;
	map<int, int> myMap;
	ii myPair;
	string Str;
	int R, P;
	cin >> Str;
	while (Str != "#")
	{
		cin >> R >> P;
		myVet.push_back(make_pair(P, R));
		myMap[R] = P;
		cin >> Str;
	}
	priority_queue<ii, vector<ii>, greater<ii> > myPQ (myVet.begin(), myVet.end());
	vector<ii> Aux;
	int K; cin >> K;
	while(K--)
	{
		myPair = myPQ.top();
		myPQ.pop();
		cout << myPair.s << '\n';
		myPQ.push(ii(myPair.f + myMap[myPair.s], myPair.s));
	}
}