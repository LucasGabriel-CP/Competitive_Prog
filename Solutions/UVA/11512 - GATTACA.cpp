#include <bits/stdc++.h>

using namespace std;

struct MinQueue {
    deque<std::pair<int,int>> q;
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
    vector<int> SA, LCP, idx;
    string Str;
    int n;
public:
    SuffixArray(const int& n_, const string& Str_){
        n = n_;
        Str = Str_;
        SA.resize(n);
        LCP.resize(n);
        idx.assign(n, 0);
        build();
        computeLCP();
    }
    SuffixArray(const int& n_, const string& Str_, const vector<int>& idx_){
        n = n_;
        Str = Str_;
        idx = idx_;
        SA.resize(n);
        LCP.resize(n);
        build();
        computeLCP();
    }

    void build(){
        const int Alpha = 256;
        vector<int> Rank(n), Cnt(max(Alpha, n), 0);
        for (int i = 0; i < n; ++i)     Cnt[Str[i]]++;
        for (int i = 1; i < Alpha; ++i) Cnt[i] += Cnt[i - 1];
        for (int i = 0; i < n; ++i)     SA[--Cnt[Str[i]]] = i;
        Rank[SA[0]] = 0;
        int Classes = 1;
        for (int i = 1; i < n; ++i){
            if (Str[SA[i]] != Str[SA[i - 1]]) ++Classes;
            Rank[SA[i]] = Classes - 1;
        }
        vector<int> TempSA(n), TempRank(n);
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
        vector<int> Phi(n), PLCP(n, 0);
        Phi[SA[0]] = -1;
        for (int i = 1; i < n; ++i)
            Phi[SA[i]] = SA[i-1];
        for (int i = 0, L = 0; i < n; ++i){
            if  (Phi[i] == -1){ PLCP[i] = 0; continue; }
            while ((i+L < n) && (Phi[i]+L < n) && (Str[i+L] == Str[Phi[i]+L])) ++L;
            PLCP[i] = L;
            L = max(L-1, 0);
        }
        for (int i = 0; i < n; ++i)
            LCP[i] = PLCP[SA[i]];
    }

    int LCS(int const& t){  //t -> quantidade de strings
        int maxLCP = -1, i, x, y;
        x = 0; y = 1;
        vector<int> has(t, 0);
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
                maxLCP = max(maxLCP, mq.min());
                where = idx[SA[x++]];
                has[where]--;
                mq.pop();
            }
        }
        return maxLCP;
    }

    int LRS(string& ans){
        string aux;
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
        for (int i = 0; i < n; ++i){
            cout << "[" << i << "] " << SA[i] << ": " << LCP[i] << " -> ";
            for (int l = SA[i]; l < n; ++l) cout << Str[l];
            cout << '\n';
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    string ans, str;
    int c; cin >> c;
    while(c--){
        cin >> str;
        str += '$';
        SuffixArray SA((int)str.size(), str);
        int t = SA.LRS(ans);
        if (ans == "") cout << "No repetitions found!\n";
        else cout << ans << ' ' << t << '\n';
    }

    return 0;
}
