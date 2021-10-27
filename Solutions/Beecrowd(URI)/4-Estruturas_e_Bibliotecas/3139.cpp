#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

typedef long long ll;

int main()
{
	ll N, M; scanf("%lld %lld", &N, &M);
	queue<int> myQ, Temp;
	ll Tot = N, Aux = 0;
	ll Ans = 0;
	forn(i, 30)
	{
		int Val; scanf("%d", &Val);
		myQ.push(Val);
		Aux += Val;
	}

	myQ.push((int)ceil((Aux / (double)30)));
	Tot += myQ.back();
	Ans++;
	myQ.pop();
	if (Tot >= M)
	{
		printf("%lld\n", Ans);
		return 0;
	}
	forn(i, 1000)
	{
		Aux = 0;
		Temp = myQ;
		forn(i, 30)
		{
			Aux += Temp.front();
			Temp.pop();
		}
		myQ.push((int)ceil(Aux / (double)30));
		Tot += myQ.back();
		Ans++;
		myQ.pop();
		if (Tot >= M) break;
	}
	if (Tot >= M)
		printf("%lld\n", Ans);
	else
	{
		Ans = Ans + (ceil((M - Tot) / (double)myQ.back()));
		printf("%lld\n", Ans);
	}

	return 0;
}