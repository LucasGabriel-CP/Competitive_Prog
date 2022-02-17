#include <bits/stdc++.h>

using namespace std;

#define MAXPRIME 1000000
bitset< MAXPRIME > isp;
vector<int> Primes;

void Crivo(){
	isp.set();
	isp[0] = isp[1] = 0;
	for (ll p = 2; p <= MAXPRIME; ++p){
		if (isp[p]){
			for (ll k = 2 * p; k <= MAXPRIME; k += p)
				isp[k] = 0;
			Primes.push_back((int)p);
		}
	}
}

bool isprime(int n) {
    if (n < MAXPRIME) return isp[n];
    for (int p : Primes) {
        if ((ll)p * p > n) return 1;
        if (n % p == 0) return 0;
    }
    assert(0);
}
