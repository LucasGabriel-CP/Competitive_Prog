#include <bits/stdc++.h>

struct FenwickTree{
    std::vector<int> BIT;
    int n;
    FenwickTree(std::vector<int> const& vet_){
        n = (int)vet_.size();
        BIT.assign(n+1, 0);
        for (int i = 0; i < n; ++i)
            upd(i + 1, vet_[i]);
    }
    int query(int id){
        int Sum = 0;
        for (; id; id -= (id & -id))
            Sum += BIT[id];
        return Sum;
    }
    void upd(int id, int val){
        for (; id <= n; id += (id & -id))
            BIT[id] += val;
    }
    int query(int l, int r){
        return query(r) - (l == 1 ? 0 : query(l - 1));
    }
};
