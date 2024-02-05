const int maxn = (int)2e5 + 50, inf = (int)1e9, mod = 1000000007;
using i64 = i64;

i64 FastExpo(i64 x, i64 n) {
    i64 res = 1;
    while (n) {
        if (n & 1)
            res = res * x;
        x = x * x;
        n >>= 1;
    }
    return res;
}

struct Matrix {
    i64 a[2][2];
    Matrix() {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                a[i][j] = 0;
            }
        }
    }
    Matrix operator *(Matrix other) {
        Matrix product = Matrix();
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    product.a[i][k] += a[i][j] * other.a[j][k];
                    product.a[i][k] %= mod;
                }
            }
        }
        return product;
    }
};

Matrix matrix_power(Matrix a, i64 n) {
    Matrix res = Matrix();
    res.a[0][0] = res.a[1][1] = 1;
    while(n) {
        if(n % 2) {
            res = res * a;
        }
        n /= 2;
        a = a * a;
    }
    return res;
}

int main(){
    
}