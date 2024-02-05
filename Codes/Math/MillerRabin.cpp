using namespace std;

typedef vector<int> vi;
typedef long long ll;
int n;

ll FastExpo(ll x, ll b, ll p){
    ll ans = 1;
    x %= p;
    while(b){
        if (b & 1) ans = (ans * x) % p;
        x = x * x % p;
        b >>= 1;
    }
    return ans;
}

bool isPrime(ll x){
    if (x < 4) return x == 2 || x == 3;
    if (x % 2 == 0) return false;
    ll d = x - 1;
    int r = __builtin_ctzll(d);
    d >>= r;
    ll bases[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    for (ll a : bases)
        if (a %= x){
            a = FastExpo(a, d, x);
            if (a == 1 || a == x - 1) continue;
            for(ll i = 1; i < r && 1 < a && a < x - 1; ++i){
                a = (a * a) % x;
            }
            if (a != x - 1) return false;
        }
    return true;
}

int main(){

    return 0;
}
