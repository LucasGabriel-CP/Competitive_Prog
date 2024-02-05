int vet[(int)2e5+5], blocks[450]; //sqrt(2e5) < 450
int block_sz;

void upd(int x, const int &v){
    blocks[x/block_sz] -= vet[x];
    vet[x] = v;
    blocks[x/block_sz] += vet[x];
}

int query(int r){ //[0...r]
    int ans = 0;
    for (int i = 0; i < r/block_sz; ++i) ans += blocks[i];
    for (int i = r/block_sz * block_sz; i < r; ++i) ans += vet[i];
    return ans;
}

int query(int l, int r){
    return query(r) - query(l-1);
}

int main(){
    int n, q; std::cin >> n >> q;
    block_sz = (int)sqrt(n);
    memset(blocks, 0, sizeof(blocks));
    for (int i = 0; i < n; i++) std::cin >> vet[i];
    for (int i = 0; i < n; i++) blocks[i/block_sz] += vet[i];
    while(q--){
        int t, l, r; std::cin >> t >> l >> r;
        if (t) upd(l-1, r);
        else std::cout << query(l , r) << '\n';
    }
}
