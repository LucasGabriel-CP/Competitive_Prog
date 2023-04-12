#include <bits/stdc++.h>

const int inf = (int)1e9;

template<typename T>
class SegTree {
    #define mid (l + ((r - l) >> 1))
    #define nil inf
private:
    int n;
    std::vector<T> seg;
    T modify(T a, T b) {
        return T(std::min(a, b));
    }
    void build(int id, int l, int r, std::vector<T> const& vet) {
        if (l == r) seg[id] = vet[l];
        else {
            build(2 * id, l, mid, vet);
            build(2 * id + 1, mid + 1, r, vet);
            seg[id] = modify(seg[2 * id], seg[2 * id + 1]);
        }
    }
    T query(int id, int l, int r, int x, int y) {
        if (x > r || y < l)   return nil;
        if (l >= x && r <= y) return seg[id];
        T p1 = query(2 * id, l, mid, x, y);
        T p2 = query(2 * id + 1, mid + 1, r, x, y);
        return modify(p1, p2);
    }
    void update(int id, int l, int r, int x, T val) {
        if (x > r || x < l)  return;
        if (l == x && r == x) {
            seg[id] = val;
            return;
        }
        update(2 * id, l, mid, x, val);
        update(2 * id + 1, mid + 1, r, x, val);
        seg[id] = modify(seg[2 * id], seg[2 * id + 1]);
    }
public:
    SegTree(){ }
    SegTree(int n_) {
        n = n_;
        seg.assign(4 * n, nil);
    }
    SegTree(std::vector<T> const& A) {
        n = (int)A.size();
        seg.resize(4 * n);
        build(1, 0, n - 1, A);
    }
    T query(int x, int y) { return query(1, 0, n - 1, x - 1, y - 1); }
    void update(int x, T val) { update(1, 0, n - 1, x - 1, val); }
};


