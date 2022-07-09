#include <bits/stdc++.h>

using namespace std;

vector<int> build(string const& Str){
    int n = Str.length();
    const int Alpha = 256;
    vector<int> SA(n), Rank(n), Cnt(max(Alpha, n), 0);
    for (int i = 0; i < n; ++i)
        Cnt[Str[i]]++;
    for (int i = 1; i < Alpha; ++i)
        Cnt[i] += Cnt[i - 1];
    for (int i = 0; i < n; ++i)
        SA[--Cnt[Str[i]]] = i;
    Rank[SA[0]] = 0;
    int Classes = 1;
    for (int i = 1; i < n; ++i){
        if (Str[SA[i]] != Str[SA[i - 1]])
            Classes++;
        Rank[SA[i]] = Classes - 1;
    }

    vector<int> TempSA(n), TempRank(n);
    for (int h = 0; (1 << h) < n; ++h){
        for (int i = 0; i < n; ++i){
            TempSA[i] = SA[i] - (1 << h);
            if (TempSA[i] < 0) TempSA[i] += n;
        }
        fill(Cnt.begin(), Cnt.begin() + Classes, 0);
        for (int i = 0; i < n; ++i)
            Cnt[Rank[TempSA[i]]]++;
        for (int i = 1; i < Classes; ++i)
            Cnt[i] += Cnt[i-1];
        for (int i = n-1; i >= 0; --i)
            SA[--Cnt[Rank[TempSA[i]]]] = TempSA[i];
        TempRank[SA[0]] = 0;
        Classes = 1;
        for (int i = 1; i < n; ++i){
            pair<int, int> Cur = { Rank[SA[i]], Rank[(SA[i] + (1 << h)) % n] };
            pair<int, int> prev = { Rank[SA[i-1]], Rank[(SA[i-1] + (1 << h)) % n] };
            if (Cur != prev)
                ++Classes;
            TempRank[SA[i]] = Classes-1;
        }
        Rank.swap(TempRank);
    }

    return SA;
}

vector<int> computeLCP(vector<int> const& SA, string const& T, int const& n){
    vector<int> Phi(n), PLCP(n, 0), LCP(n);
    Phi[SA[0]] = -1;
    for (int i = 1; i < n; ++i)
        Phi[SA[i]] = SA[i-1];
    for (int i = 0, L = 0; i < n; ++i){
        if  (Phi[i] == -1){ PLCP[i] = 0; continue; }
        while ((i+L < n) && (Phi[i]+L < n) && (T[i+L] == T[Phi[i]+L])) ++L;
        PLCP[i] = L;
        L = max(L-1, 0);
    }
    for (int i = 0; i < n; ++i)
        LCP[i] = PLCP[SA[i]];
    return LCP;
}

int LCS(vector<int> const& SA, vector<int> const& LCP, int const& splitId, int const& n){
    int maxLCP = -1;
    for (int i = 1; i < n; ++i){
        if ((SA[i] < splitId) == (SA[i-1] < splitId)) continue;
        maxLCP = max(maxLCP, LCP[i]);
    }
    return maxLCP;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    string Str1, Str2, T, Aux;
    //Uma string
    cin >> Str1;
    Str1 += '$';
    T = Str1;
    int n = (int)T.size();
    vector<int> SA = build(T);
    vector<int> LCP = computeLCP(SA, T, n);
    //Mais de uma
    cin >> Str1 >> Str2;
    Str1 += '$';
    Str2 += '#';
    T = Str1;
    T += Str2;
    int splitId = (int)Str1.size();
    n = (int)T.size();
    vector<int> SuffixArr = build(T);
    vector<int> LCP = computeLCP(SuffixArr, T, n);
    cout << LCS(SuffixArr, LCP, splitId, n) << '\n';

    return 0;
}
