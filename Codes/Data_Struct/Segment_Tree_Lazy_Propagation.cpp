#include <bits/stdc++.h>

using namespace std;

#define Mid ((l + r) >> 1)
#define nil 0
typedef int no;

class SegTree{
private:
    int n;
    vector<no> lazy, seg;
    no modify(no &a, no &b){
        return a + b;
    }
    void push(int id, bool child){
        no &l = lazy[id];
        if (l){
            seg[id] += l;
            if (child){
                lazy[2*id] += l;
                lazy[2*id+1] += l;
            }
            l = 0;
        }
    }
    void build(int id, int l, int r, vector<int> const& vet){
        if(l == r) seg[id] = vet[l];
        else{
            build(2*id, l, Mid);
            build(2*id+1, Mid+1, r);
            seg[id] = modify(seg[2*id], seg[2*id+1]);
        }
    }
    no query(int id, int l, int r, int x, int y){
        push(id, r-l);
        if(x > r || y < l)   return nil; //doens't change ans
        if(l >= x && r <= y) return seg[id];
        no p1 = query(2*id, l, Mid, x, y);
        no p2 = query(2*id+1, Mid+1, r, x, y);
        return modify(p1, p2);
    }
    void update(int id, int l, int r, int x, int y, no val){
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
    SegTree(vector<int> const& A){
        n = (int)A.size();
        seg.resize(4*n);
        lazy.assign(4*n, 0);
        build(1, 0, n-1);
    }
    no query(int x, int y){ return query(1, 0, n-1, x-1, y-1); }
    void update(int x, int y, no val){ update(1, 0, n-1, x-1, y-1, val); }
};
