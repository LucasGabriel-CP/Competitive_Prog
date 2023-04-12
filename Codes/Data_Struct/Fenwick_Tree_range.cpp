#include <bits/stdc++.h>

template<typename T>
struct FenwickTree{
    std::vector<T> BIT;
    int n;
    FenwickTree(std::vector<T> const& vet_){
        n = (int)vet_.size();
        BIT.assign(2, std::vector<T>(n + 2));
        for (int i = 1; i <= n; ++i)
            BIT[1][std::min(n + 1, i + (i & -i))] += BIT[1][i] += vet_[i - 1];
    }
    T get(int x, int id){
        T sum = 0;
        for (; id; id -= (id & -id)) sum += BIT[x][id];
        return sum;
    }
    T get(int p){
        return get(0, p) * p + get(1, p);
    }
    T query(int l, int r){
        return get(r) - get(l - 1);
    }
    void add(int x, int id, T val){
        for (; id <= n; id += (id & -id)) BIT[x][id] += val;
    }
    void update(int id, T val){
        add(0, l, val); add(0, r + 1, -val);
        add(1, l, -val*(l - 1)); add(1, r + 1, val*r);
    }
};
