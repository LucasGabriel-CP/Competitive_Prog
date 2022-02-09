//Range Sum with addition to segments
#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000055
#define Mid ((l + r) >> 1)

typedef long long ll;
typedef int no;

int N;
int lazy[4 * MAXN];
no Seg[4 * MAXN], Vet[MAXN];

void Modify(no& t, no& a, no& b){ //Fazer a modificação no nó
    t = a + b;
}

void Give(int l, int r, ll la, no& t){ //Mandar a preguiça pro nó
    t += (la * (r - l));
}

void prop(int id, int l, int r){ //Propagar a preguiça, se houver
    if (lazy[id]){
        Give(l, r, lazy[id], Seg[id]);
        if (l != r){ //Mandar pros filhos
            lazy[2 * id] += lazy[id];
            lazy[2 * id + 1] += lazy[id];
        }
        lazy[id] = 0; //remover preguiça
    }
}

void build(int id = 1, int l = 0, int r = N){ //[l,r)
    lazy[id] = 0;
    if (r - l < 2)
        Seg[id] = Vet[l];
    else{
        build(2 * id, l, Mid);
        build(2 * id + 1, Mid, r);
        Modify(Seg[id], Seg[2*id], Seg[2*id+1]);
    }
}

void Update(int i, int j, int x, int l = 0, int r = N, int id = 1){ //[l,r)
    if (i <= l && r <= j){//caso esteja no range, atribui a preguiça
        lazy[id] += x;
        prop(id, l, r);
        return;
    }
    prop(id, l, r);
    if (i >= r || l >= j) return;

    Update(i, j, x, l, Mid, 2 * id);
    Update(i, j, x, Mid, r, 2 * id + 1);

    Modify(Seg[id], Seg[2 * id], Seg[2 * id + 1]);
}

no query(int i, int j, int l = 0, int r = N, int id = 1){ //[l,r)
    if (i >= r || l >= j) return 0;
    prop(id, l, r);
    if (i <= l && r <= j) return Seg[id];

    no Op1 = query(i, j, l, Mid, 2 * id);
    no Op2 = query(i, j, Mid, r, 2 * id + 1);
    no ans = 0; Modify(ans, Op1, Op2);
    return ans;
}
