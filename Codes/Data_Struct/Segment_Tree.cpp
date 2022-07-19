#include <bits/stdc++.h>

using namespace std;

#define Mid ((l + r) >> 1)
#define nil 0
typedef int no;

//Find the sum on a interval and other stuff
class SegTree{
private:
    int n;
    vector<no> vet, seg;
    //Function to do what I want
    no modify(no a, no b){
        return a + b;
    }
    void build(int id, int l, int r){
        if(l == r) seg[id] = vet[l];
        else{
            build(2*id, l, Mid);
            build(2*id+1, Mid+1, r);
            seg[id] = modify(seg[2*id], seg[2*id+1]);
        }
    }
    no query(int id, int l, int r, int x, int y){
        if(x > r || y < l)   return nil; //doens't change ans
        if(l >= x && r <= y) return seg[id];
        no p1 = query(2*id, l, Mid, x, y);
        no p2 = query(2*id+1, Mid+1, r, x, y);
        return modify(p1, p2);
    }
    void update(int id, int l, int r, int x, no val){
        if(x > r || x < l)  return;
        if(l == x && r == x){
            vet[x] = val;
            seg[id] = vet[l];
            return;
        }
        update(2*id, l, Mid, x, val);
        update(2*id+1, Mid+1, r, x, val);
        seg[id] = modify(seg[2*id], seg[2*id+1]);
    }
public:
    SegTree(vector<int> const& A){
        vet = A;
        n = (int)A.size();
        seg.resize(4*n);
        build(1, 0, n-1);
    }
    no query(int x, int y){ return query(1, 0, n-1, x-1, y-1); }
    void update(int x, no val){ update(1, 0, n-1, x-1, val); }
};
