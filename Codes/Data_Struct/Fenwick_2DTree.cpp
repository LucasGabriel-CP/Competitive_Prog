#define MAXN 1050

int BIT[MAXN][MAXN];

void upd(int x, int y, int N, int val = 1){
    while(x <= N){
        int y1 = y;
        while(y1 <= N){
            BIT[x][y1] += val;
            y1 += (y1 & -y1);
        }
        x += (x & -x);
    }
}

int query(int x, int y){
    int soma = 0;
    while(x){
        int y1 = y;
        while(y1){
            soma += BIT[x][y1];
            y1 -= (y1 & -y1);
        }
        x -= (x & -x);
    }
    return soma;
}

int query(int x1, int y1, int x2, int y2){
    return (query(x2, y2) - query(x1 - 1, y2)
            - query(x2, y1 - 1) + query(x1 - 1, y1 - 1));
}
