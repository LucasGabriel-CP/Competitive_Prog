/*
    (๑ᵔ⤙ᵔ๑)⋆˚✿˖°
*/

template<typename T>
struct FenwickTree{
    std::vector<T> BIT;
    int n;
    FenwickTree(std::vector<T> const& vet_){
        n = (int)vet_.size();
        BIT.assign(n+1, 0);
        for (int i = 0; i < n; ++i)
            upd(i + 1, vet_[i]);
    }
    T query(int id){
        T sum = 0;
        for (; id; id -= (id & -id)) sum += BIT[id];
        return sum;
    }
    void upd(int id, T val){
        for (; id <= n; id += (id & -id)) BIT[id] += val;
    }
    T query(int l, int r){
        return query(r) - (l == 1 ? 0 : query(l - 1));
    }
};
