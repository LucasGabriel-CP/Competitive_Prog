#include<bits/stdc++.h>

const int maxn = (int)2e5 + 50, inf = (int)1e9, maxlogn = 20;
using i64 = long long;

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

typedef std::vector<std::vector<int>> matrix_int;

matrix_int matrix_product(const matrix_int &a, const matrix_int &b){
    matrix_int ans;

    for(int i = 0; i < a.size(); i++){
        ans.push_back({});
        for(int j = 0; j < b[0].size(); j++){
            ans.back().push_back({});
            for(int k = 0; k < b.size(); k++){
                ans.back().back() = ans.back().back() + a[i][k] * b[k][j];
            }
        }
    }

    return ans;
}

matrix_int fast_matrix_pow(matrix_int x, int n){
    matrix_int res = {{1,0},{0,1}};
    while (n) {
        if (n & 1)
            res = matrix_product(res, x);
        x = matrix_product(x, x);
        n >>= 1;
    }
    return res;
}

int main(){
    
}