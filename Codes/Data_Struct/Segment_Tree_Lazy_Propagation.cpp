#include <bits/stdc++.h>

template<typename T>
class SegTree{
private:
    #define Mid ((l + r) >> 1)
    #define nil 0
    int n;
    std::vector<T> lazy, seg;
    T modify(T &a, T &b){
        return T(a + b);
    }
    void push(int id, bool child){
        T &l = lazy[id];
        if (l){
            seg[id] += l;
            if (child){
                lazy[2*id] += l;
                lazy[2*id+1] += l;
            }
            l = 0;
        }
    }
    void build(int id, int l, int r, std::vector<T> const& vet){
        if(l == r) seg[id] = vet[l];
        else{
            build(2*id, l, Mid, vet);
            build(2*id+1, Mid+1, r, vet);
            seg[id] = modify(seg[2*id], seg[2*id+1]);
        }
    }
    T query(int id, int l, int r, int x, int y){
        push(id, r-l);
        if(x > r || y < l)   return nil; //doens't change ans
        if(l >= x && r <= y) return seg[id];
        T p1 = query(2*id, l, Mid, x, y);
        T p2 = query(2*id+1, Mid+1, r, x, y);
        return modify(p1, p2);
    }
    void update(int id, int l, int r, int x, int y, T val){
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
    SegTree(){ }
    SegTree(std::vector<T> const& A){
        n = (int)A.size();
        seg.resize(4*n);
        lazy.assign(4*n, 0);
        build(1, 0, n-1, A);
    }
    T query(int x, int y){ return query(1, 0, n-1, x-1, y-1); }
    void update(int x, int y, T val){ update(1, 0, n-1, x-1, y-1, val); }
};


/*
PEGADO DA UFMG https://github.com/brunomaletta/Biblioteca/blob/master/Codigo/Estruturas/Segtree/segTree.cpp
  Se tiver uma seg de max, da pra descobrir em O(log(n))
o primeiro e ultimo elemento >= val numa range:

primeira posicao >= val em [a, b] (ou -1 se nao tem)
int get_left(int a, int b, T val, int p=1, int l=0, int r=n-1) {
	push(p, r - l);
	if (b < l or r < a or seg[p] < val) return -1;
	if (r == l) return l;
	int m = (l+r)/2;
	int x = get_left(a, b, val, 2*p, l, m);
	if (x != -1) return x;
	return get_left(a, b, val, 2*p+1, m+1, r);
}

ultima posicao >= val em [a, b] (ou -1 se nao tem)
int get_right(int a, int b, T val, int p=1, int l=0, int r=n-1) {
	push(p, r - l);
	if (b < l or r < a or seg[p] < val) return -1;
	if (r == l) return l;
	int m = (l+r)/2;
	int x = get_right(a, b, val, 2*p+1, m+1, r);
	if (x != -1) return x;
	return get_right(a, b, val, 2*p, l, m);
}

  Se tiver uma seg de soma sobre um array nao negativo v, da pra
descobrir em O(log(n)) o maior j tal que v[i]+v[i+1]+...+v[j-1] < val
int lower_bound(int i, T& val, int p=1, int l=0, int r=n-1) {
	push(p, r - l);
	if (r < i) return n;
	if (i <= l and seg[p] < val) {
		val -= seg[p];
		return n;
	}
	if (l == r) return l;
	int m = (l+r)/2;
	int x = lower_bound(i, val, 2*p, l, m);
	if (x != n) return x;
	return lower_bound(i, val, 2*p+1, m+1, r);
}

*/