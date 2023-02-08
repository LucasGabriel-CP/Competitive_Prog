#include <bits/stdc++.h>

const int inf = (int)1e9;

struct Node{
    int x;
    Node(int x_) : x(x_){ }
};

class SegTree {
    #define mid (l + ((r - l) >> 1))
    #define nil Node(inf)
private:
    int n;
    std::vector<Node> seg;
    Node modify(Node a, Node b) {
        return Node(std::min(a.x, b.x));
    }
    void build(int id, int l, int r, std::vector<int> const& vet) {
        if (l == r) seg[id].x = vet[l];
        else {
            build(2 * id, l, mid, vet);
            build(2 * id + 1, mid + 1, r, vet);
            seg[id] = modify(seg[2 * id], seg[2 * id + 1]);
        }
    }
    Node query(int id, int l, int r, int x, int y) {
        if (x > r || y < l)   return nil;
        if (l >= x && r <= y) return seg[id];
        Node p1 = query(2 * id, l, mid, x, y);
        Node p2 = query(2 * id + 1, mid + 1, r, x, y);
        return modify(p1, p2);
    }
    void update(int id, int l, int r, int x, Node val) {
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
    SegTree(int n_) {
        n = n_;
        seg.assign(4 * n, nil);
    }
    SegTree(std::vector<int> const& A) {
        n = (int)A.size();
        seg.resize(4 * n);
        build(1, 0, n - 1, A);
    }
    Node query(int x, int y) { return query(1, 0, n - 1, x - 1, y - 1); }
    void update(int x, Node val) { update(1, 0, n - 1, x - 1, val); }
};
