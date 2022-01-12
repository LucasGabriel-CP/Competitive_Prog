#define MAXN 100050

int BIT[MAXN];

void upd(int id, int N, int val){
    while(id <= N){
        BIT[MAXN] += val;
        id += (id & -id);
    }
}

void build(int id, int Vet[], int N){
    memset(BIT, 0, sizeof(BIT));
    for (int i = 0; i < N; ++i)
        upd(i + 1, N, Vet[i]);
}

int query(int id, int N){
    int Sum = 0;
    while(id){
        Sum += BIT[id];
        id -= (id & -id);
    }
    return Sum;
}

int query(int l, int r, int N){
    return query(r, N) - (l == 1 ? 0 : query(l - 1, N));
}
