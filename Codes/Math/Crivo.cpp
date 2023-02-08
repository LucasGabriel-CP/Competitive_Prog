#include <bits/stdc++.h>

using i64 = long long;
const int maxprime = (int)1e6;
std::bitset< maxprime > isp; //only works if < 1e6
std::vector<int> primes;

void Crivo(){
	isp.set();
	isp[0] = isp[1] = 0;
	for (i64 p = 2; p <= maxprime; ++p){
		if (isp[p]){
			for (i64 k = 2 * p; k <= maxprime; k += p)
				isp[k] = 0;
			primes.push_back((int)p);
		}
	}
}

bool isprime(int n) {
    if (n < maxprime) return isp[n];
    for (int p : primes) {
        if ((i64)p * p > n) return 1;
        if (n % p == 0) return 0;
    }
    assert(0);
}
