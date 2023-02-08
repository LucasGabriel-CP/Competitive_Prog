#include <bits/stdc++.h>

struct Node{
    int x;
    Node(int x_) : x(x_){ }
};

class SegTree{
private:
    #define Mid ((l + r) >> 1)
    #define nil Node(0)
    int n;
    std::vector<Node> lazy, seg;
    Node modify(Node &a, Node &b){
        return Node(a.x + b.x);
    }
    void push(int id, bool child){
        Node &l = lazy[id];
        if (l.x){
            seg[id].x += l.x;
            if (child){
                lazy[2*id].x += l.x;
                lazy[2*id+1].x += l.x;
            }
            l = 0;
        }
    }
    void build(int id, int l, int r, std::vector<int> const& vet){
        if(l == r) seg[id].x = vet[l];
        else{
            build(2*id, l, Mid, vet);
            build(2*id+1, Mid+1, r, vet);
            seg[id] = modify(seg[2*id], seg[2*id+1]);
        }
    }
    Node query(int id, int l, int r, int x, int y){
        push(id, r-l);
        if(x > r || y < l)   return nil; //doens't change ans
        if(l >= x && r <= y) return seg[id];
        Node p1 = query(2*id, l, Mid, x, y);
        Node p2 = query(2*id+1, Mid+1, r, x, y);
        return modify(p1, p2);
    }
    void update(int id, int l, int r, int x, int y, Node val){
        push(id, r-l);
        if(x > r || y < l)  return;
        if(l >= x && r <= y){
            lazy[id] = val;
            push(id, r-l);
            return;
        }
        update(2*id, l, Mid, x, y, val);
        update(2*id+1, Mid+1, r, x, y, val);
        seg[id] = modify(seg[2*id], seg[2*id+1]);
    }
public:
    SegTree(std::vector<int> const& A){
        n = (int)A.size();
        seg.resize(4*n);
        lazy.assign(4*n, 0);
        build(1, 0, n-1, A);
    }
    Node query(int x, int y){ return query(1, 0, n-1, x-1, y-1); }
    void update(int x, int y, Node val){ update(1, 0, n-1, x-1, y-1, val); }
};
