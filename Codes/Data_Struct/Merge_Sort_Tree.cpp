#include<bits/stdc++.h>
#define Mid ((l + r) >> 1)

typedef std::vector<int> vi;

const int maxn = 100003;

int n, vet[maxn], indx[maxn], next_right[maxn];
vi st[4 * maxn];

void merge(vi& dest, const vi& x, const vi& y) {
    dest.resize(x.size() + y.size());
    merge(x.begin(), x.end(), y.begin(), y.end(), dest.begin());
}

vi& build(int t = 1, int l = 0, int r = n - 1) {
    if (l == r) st[t] = {vet[l]};
    else merge(st[t], build(2*t, l, Mid), build(2*t+1, Mid + 1, r));
    return st[t];
}

// returns #values < x
int qry(int i, int j, int x, int t = 1, int l = 0, int r = n - 1) {
    if (r < i || j < l)     return 0;
    if (i <= l && r <= j)   return lower_bound(st[t].begin(), st[t].end(), x) - st[t].begin();  // upper_bound for <= x
    return qry(i, j, x, 2*t, l, Mid) + qry(i, j, x, 2*t+1, Mid + 1, r);
}

// find the k-th number of a range [l, r] if it was sorted: (check main function)[1]
//  * create an index array sorted by value: index.sort((i, j) -> value[i] < value[j])
//  * build the tree using those indexes
//  * do the following query
int kth(int i, int j, int k, int t = 1, int l = 0, int r = n - 1) {
    if (l == r) return st[t][0];
    int nl = (upper_bound(st[2*t+1].begin(), st[2*t+1].begin(), j) - st[2*t+1].begin())
            - (lower_bound(st[2*t].begin(), st[2*t].end(), i) - st[2*t].begin());       // #indexes inside range [i, j]
    if (k <= nl) return kth(i, j, k, 2*t, l, Mid);  // the lowest values are in the left tree
    return kth(i, j, k - nl, 2*t+1, Mid + 1, r);
}

// find the number of distinct numbers in a range
//  * create an next_right array to store next occurence of the element(check main)[2]
//  * build the tree using the next_array and do the following query
int qnty(int i, int j, int t = 1, int l = 0, int r = n - 1) {
    if (r < i || j < l) return 0;
    if (i <= l && r <= j)
        return st[t].end() - upper_bound(st[t].begin(), st[t].end(), j);
    return qnty(i, j, 2*t, l, Mid) + qnty(i, j, 2*t+1, Mid + 1, r);
}

int main(){
    //[1]
    std::sort(indx, indx + n, [&](int a, int b){ return vet[a] < vet[b]; });
    //[2]
    std::map<int, int> ocur;
    for (int i = n - 1; i >= 0; i--) {
        if (!ocur.count(vet[i])){
            next_right[i] = n;
            ocur[vet[i]]  = i;
        }
        else{
            next_right[i] = ocur[vet[i]];
            ocur[vet[i]]  = i;
        }
    }
    build();

    return 0;
}
