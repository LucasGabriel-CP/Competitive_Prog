#include<bits/stdc++.h>

using i64 = long long;
const int inf = (int)1e9, maxlogn = 20;

int log2_floor(unsigned long long i) {
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

template <typename T>
struct SparseTableMin{
    std::vector<std::vector<T>> st;
    int k, n;
    int modify(T const& a, T const& b){
        return std::min(a, b);
    }
    SparseTable(){ }
    SparseTable(std::vector<T> const& vet){
        n = (int)vet.size();
        k = log2_floor(n);
        st.assign(k + 1, std::vector<T>(n + 1, inf));
        for (int i = 0; i < n; i++){
            st[0][i] = vet[i];
        }
        for (int i = 1; i <= k; i++){
            for (int j = 0; j + (1 << i) <= n; j++){
                st[i][j] = modify(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
    T query(int l, int r){
        int i = log2_floor(r - l + 1);
        return modify(st[i][l], st[i][r - (1 << i) + 1]);
    }
};