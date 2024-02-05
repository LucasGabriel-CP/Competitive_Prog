//Use the primes from the crivo.cpp file
using namespace std;

using i64 = long long;
vector<i64> primes;

//Number of prime facctors
i64 numPF(int N){
    int ans = 0;
    for (int i = 0; (i < (int)primes.size()) && (primes[i] * primes[i] <= N); ++i)
        while(!(N % primes[i])) { N /= primes[i]; ++ans; }
    return ans + (N != 1);
}

//Number of divisors
i64 numDiv(int N){
    int ans = 1;
    for (int i = 0; (i < (int)primes.size()) && (primes[i] * primes[i] <= N); ++i){
        int Pows = 0;
        while(!(N % primes[i])) { N /= primes[i]; ++Pows; }
        ans *= Pows + 1;
    }
    return (N != 1) ? 2 * ans : ans;
}

//Sum of the divisors
i64 sumDiv(int N){
    int ans = 1;
    for (int i = 0; (i < (int)primes.size()) && (primes[i] * primes[i] <= N); ++i){
        int Mult = primes[i], total = 0;
        while(!(N % primes[i])) {
            N /= primes[i];
            total += Mult;
            Mult *= primes[i];
        }
        ans *= total;
    }
    return (N != 1) ? ans * (N + 1) : ans;
}

//Count p numbers that are realatively prime to N, p < N
i64 EulerPhi(int N){
    int ans = N;
    for (int i = 0; (i < (int)primes.size()) && (primes[i] * primes[i] <= N); ++i){
        if (!(N % primes[i])) ans -= ans / primes[i];
        while(!(N % primes[i])) { N /= primes[i]; }
    }
    return (N != 1) ? ans - ans/N : ans;
}

int main(){
    i64 Vet[] = {2, 3, 5, 7, 11};
    primes = vector<i64>(Vet, Vet + sizeof(Vet)/sizeof(i64));

    return 0;
}
