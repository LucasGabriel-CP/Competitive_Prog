#include <bits/stdc++.h>

using namespace std;

#define MAXN 100005
#define Mid ((l + r) >> 1)
typedef int no;

/*
* Find the sum on a interval and other stuff
*/
int N, Vet[MAXN], Seg[4 * MAXN];

//Function to do what I want
no Modify(no a, no b){
    return a + b;
}

no build(int id = 1, int l = 0, int r = N){
    if (r - l < 2)  //[l, r)
        return Seg[id] = Vet[l];  //insert value on the interval
    Seg[id] = Modify(build(2 * id, l, Mid), build(2 * id + 1, Mid, r));
}

void Update(int i, int x, int l = 0, int r = N, int id = 1){
    if (r - l < 2){
        Seg[id] = x; //Replace by x
        return;
    }
    if (i < Mid)
        Update(i, x, l, Mid, 2 * id);
    else
        Update(i, x, Mid, r, 2 * id + 1)
    Seg[id] = Modify(Seg[2*id], Seg[2*id+1]);
}

int query(int i, int j, int l = 0, int r = N, int id = 1){ //[i, j)
    if (i >= r || l >= j)
        return inf;   //Don't change the answer
    if (i <= l && r <= j)
        return Seg[id];
    return Modify(query(i, j, l, Mid, 2 * id), query(i, j, Mid, r, 2 * id + 1));
}
