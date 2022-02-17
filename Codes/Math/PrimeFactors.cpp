//Use the primes from the crivo.cpp file
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
vector<ll> Primes;

//Number of prime facctors
ll numPF(int N){
    int ans = 0;
    for (int i = 0; (i < (int)Primes.size()) && (Primes[i] * Primes[i] <= N); ++i)
        while(!(N % Primes[i])) { N /= Primes[i]; ++ans; }
    return ans + (N != 1);
}

//Number of divisors
ll numDiv(int N){
    int ans = 1;
    for (int i = 0; (i < (int)Primes.size()) && (Primes[i] * Primes[i] <= N); ++i){
        int Pows = 0;
        while(!(N % Primes[i])) { N /= Primes[i]; ++Pows; }
        ans *= Pows + 1;
    }
    return (N != 1) ? 2 * ans : ans;
}

//Sum of the divisors
ll sumDiv(int N){
    int ans = 1;
    for (int i = 0; (i < (int)Primes.size()) && (Primes[i] * Primes[i] <= N); ++i){
        int Mult = Primes[i], total = 0;
        while(!(N % Primes[i])) {
            N /= Primes[i];
            total += Mult;
            Mult *= Primes[i];
        }
        ans *= total;
    }
    return (N != 1) ? ans * (N + 1) : ans;
}

//Count p numbers that are realatively prime to N, p < N
ll EulerPhi(int N){
    int ans = N;
    for (int i = 0; (i < (int)Primes.size()) && (Primes[i] * Primes[i] <= N); ++i){
        if (!(N % Primes[i])) ans -= ans / Primes[i];
        while(!(N % Primes[i])) { N /= Primes[i]; }
    }
    return (N != 1) ? ans - ans/N : ans;
}

int main(){
    ll Vet[] = {2, 3, 5, 7, 11};
    Primes = vector<ll>(Vet, Vet + sizeof(Vet)/sizeof(ll));

    return 0;
}
