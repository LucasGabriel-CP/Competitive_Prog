#include <bits/stdc++.h>


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

class SuffixArray{
private:
    std::vector<int> SA, LCP, idx;
    std::string Str;
    int n;
public:
    SuffixArray(const int& n_, const std::string& Str_){
        n = n_;
        Str = Str_;
        SA.resize(n);
        LCP.resize(n);
        idx.assign(n, 0);
        build();
    }
    SuffixArray(const int& n_, const std::string& Str_, const std::vector<int>& idx_){
        n = n_;
        Str = Str_;
        idx = idx_;
        SA.resize(n);
        LCP.resize(n);
        build();
    }

    void build(){
        const int Alpha = 256;
        std::vector<int> Rank(n), Cnt(std::max(Alpha, n), 0);
        for (int i = 0; i < n; ++i)     Cnt[Str[i]]++;
        for (int i = 1; i < Alpha; ++i) Cnt[i] += Cnt[i - 1];
        for (int i = 0; i < n; ++i)     SA[--Cnt[Str[i]]] = i;
        Rank[SA[0]] = 0;
        int Classes = 1;
        for (int i = 1; i < n; ++i){
            if (Str[SA[i]] != Str[SA[i - 1]]) ++Classes;
            Rank[SA[i]] = Classes - 1;
        }
        std::vector<int> TempSA(n), TempRank(n);
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

    void computeLCP(){
        std::vector<int> Phi(n), PLCP(n, 0);
        Phi[SA[0]] = -1;
        for (int i = 1; i < n; ++i)
            Phi[SA[i]] = SA[i-1];
        for (int i = 0, L = 0; i < n; ++i){
            if  (Phi[i] == -1){ PLCP[i] = 0; continue; }
            while ((i+L < n) && (Phi[i]+L < n) && (Str[i+L] == Str[Phi[i]+L])) ++L;
            PLCP[i] = L;
            L = std::max(L-1, 0);
        }
        for (int i = 0; i < n; ++i)
            LCP[i] = PLCP[SA[i]];
    }

    int LCS(int const& t){  //t -> quantidade de strings
        int maxLCP = -1, i, x, y;
        x = 0; y = 1;
        std::vector<int> has(t, 0);
        MinQueue mq;
        int where = idx[SA[x]];
        has[where]++;
        where = idx[SA[y]];
        has[where]++;
        mq.push(LCP[y]);
        while(y < n){
            for(i = 0; i < t && has[i]; ++i);
            if (i < t){
                ++y;
                if (y >= n) break;
                where = idx[SA[y]];
                has[where]++;
                mq.push(LCP[y]);
            }
            else{
                maxLCP = std::max(maxLCP, mq.min());
                where = idx[SA[x++]];
                has[where]--;
                mq.pop();
            }
        }
        return maxLCP;
    }

    int LRS(std::string& ans){
        std::string aux;
        int id, maior = 0, qnt = 0;
        for (int i = 0; i < n; ++i){
            if (maior < LCP[i]){
                qnt = 2;
                id = i;
                maior = LCP[i];
            }
            else if (maior && maior == LCP[i] && maior == LCP[i-1]) ++qnt;
        }
        ans = "";
        for (int i = 0; i < maior; ++i){
            ans += Str[i + SA[id]];
        }
        return qnt;
    }

    void printSA(){
        std::cout << n << '\n';
        for (int i = 0; i < n; ++i){
            std::cout << "[" << i << "] " << SA[i] << ": " << LCP[i] << " -> ";
            for (int l = SA[i]; l < n; ++l)
                std::cout << Str[l];
            std::cout << '\n';
        }
    }
};

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    std::string Str1, Str2, T, Aux;

    //Uma string
    std::cin >> Str1;
    Str1 += '$'; //Simbolo com valor menor que o alfabeto
    T = Str1;
    int n = (int)T.size();
    SuffixArray SA1(n, T);
    SA1.computeLCP();
    SA1.printSA();
    std::cout << "--------\n";
    //Mais de uma
    std::cin >> Str1 >> Str2;
    Str1 += '$';
    Str2 += '#';
    T = Str1;
    T += Str2;
    n = (int)T.size();
    std::vector<int> idx(n);
    int k = 0;
    for(int i = 0; i < n; ++i){
        idx[i] = k;
        if (T[i] < 'A') ++k;
    }
    SuffixArray SA2(n, T, idx);
    SA2.computeLCP();
    SA2.printSA();
    std::cout << SA2.LCS(k) << '\n';

    return 0;
}
