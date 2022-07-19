#include <bits/stdc++.h>

const int maxn = (int)1e6+50;
int LCP[maxn], SA[maxn], vet[maxn], Cnt[maxn], Rank[maxn], TempSA[maxn], TempRank[maxn];
char inpt[(int)1e5+50], Str[maxn];

struct MinQueue {
    std::deque<std::pair<int,int>> q;
    void push(int x) {
        int k = 1;
        for (; !q.empty() && x <= q.back().first; q.pop_back()) k += q.back().second;
        q.emplace_back(x, k);
    }
    inline int min() { return q.front().first; }
    inline void pop() { if (!--q.front().second) q.pop_front(); }
};

void build(int const& n){
    const int Alpha = 256;
    int tam = std::max(Alpha, n);
    for (int i = 0; i < tam; ++i)   Cnt[i] = 0;
    for (int i = 0; i < n; ++i)     Cnt[Str[i]]++;
    for (int i = 1; i < Alpha; ++i) Cnt[i] += Cnt[i - 1];
    for (int i = 0; i < n; ++i)     SA[--Cnt[Str[i]]] = i;
    Rank[SA[0]] = 0;
    int Classes = 1;
    for (int i = 1; i < n; ++i){
        if (Str[SA[i]] != Str[SA[i - 1]]) Classes++;
        Rank[SA[i]] = Classes - 1;
    }

    std::pair<int, int> Cur, prev;
    int aux, aux1;
    for (int h = 0, pw = (1 << h); pw < n;){
        for (int i = 0; i < n; ++i){
            TempSA[i] = SA[i] - pw;
            if (TempSA[i] < 0) TempSA[i] += n;
        }
        for (int i = 0; i < Classes; ++i) Cnt[i] = 0;
        for (int i = 0; i < n; ++i){
            aux = Rank[TempSA[i]];
            Cnt[aux]++;
        }
        for (int i = 1; i < Classes; ++i) Cnt[i] += Cnt[i-1];
        for (int i = n-1; i >= 0; --i){
            aux = --Cnt[Rank[TempSA[i]]];
            SA[aux] = TempSA[i];
        }
        TempRank[SA[0]] = 0;
        Classes = 1;
        for (int i = 1; i < n; ++i){
            aux = SA[i] + pw;
            while (aux >= n) aux -= n;
            aux1 = SA[i-1] + pw;
            while (aux1 >= n) aux1 -= n;
            if (Rank[SA[i]] != Rank[SA[i-1]] || Rank[aux] != Rank[aux1]) ++Classes;
            TempRank[SA[i]] = Classes-1;
        }
        for (int i = 0; i < n; ++i) Rank[i] = TempRank[i];
        pw = (1 << (++h));
    }
}

void computeLCP(int const& n){
    std::vector<int> Phi(n), PLCP(n, 0);
    Phi[SA[0]] = -1;
    for (int i = 1; i < n; ++i) Phi[SA[i]] = SA[i-1];
    for (int i = 0, L = 0; i < n; ++i){
        if  (Phi[i] == -1){ PLCP[i] = 0; continue; }
        while ((i+L < n) && (Phi[i]+L < n) && (Str[i+L] == Str[Phi[i]+L])) ++L;
        PLCP[i] = L;
        L = std::max(L-1, 0);
    }
    for (int i = 0; i < n; ++i) LCP[i] = PLCP[SA[i]];
}

int LCS(int const& n, int const& t){
    int maxLCP = -1, i, x, y;
    x = 0; y = 1;
    std::vector<int> has(t, 0);
    MinQueue mq;
    int where = vet[SA[x]];
    has[where]++;
    where = vet[SA[y]];
    has[where]++;
    mq.push(LCP[y]);
    while(y < n){
        for(i = 0; i < t && has[i]; ++i);
        if (i < t){
            ++y;
            if (y >= n) break;
            where = vet[SA[y]];
            has[where]++;
            mq.push(LCP[y]);
        }
        else{
            maxLCP = std::max(maxLCP, mq.min());
            where = vet[SA[x++]];
            has[where]--;
            mq.pop();
        }
    }

    return maxLCP;
}

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    char enc[11] = {'-', ',', '@', '#', '$', '%', '^', '&', '*', '('};
    int len, k;
    len = k = 0;
    while(std::cin >> inpt){
        int size = strlen(inpt);
        for (int i = len; i < len + size; i++) Str[i] = inpt[i-len], vet[i] = k;
        vet[len + size] = k;
        Str[len + size] = enc[k];
        len += size + 1;
        k++;
    }
    int n = len;
    build(n);
    computeLCP(n);
    std::cout <<  LCS(n, k) << '\n';
    return 0;
}
