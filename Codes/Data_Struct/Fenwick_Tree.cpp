#include <bits/stdc++.h>

using namespace std;

class FenwickTree{
private:
    vector<int> BIT;
    int n;
    int query(int id){
        int Sum = 0;
        for (; id; id -= (id & -id))
            Sum += BIT[id];
        return Sum;
    }

public:
    FenwickTree(vector<int> const& vet_){
        n = (int)vet_.size();
        BIT.assign(n+1, 0);
        for (int i = 0; i < n; ++i)
            upd(i + 1, vet_[i]);
    }
    void upd(int id, int val){
        for (; id <= n; id += (id & -id))
            BIT[id] += val;
    }
    int query(int l, int r){
        return query(r) - (l == 1 ? 0 : query(l - 1));
    }
};
