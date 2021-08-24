vector<int> build(string& Str)
{
    int n = Str.length();
    const int Alpha = 256;
    vi SA(n), Rank(n), Cnt(max(Alpha, n), 0);

    //Utilizando Counting Sort na primeira iteração
    for (int i = 0; i < n; ++i)
        Cnt[Str[i]]++;
    for (int i = 1; i < Alpha; ++i)
        Cnt[i] += Cnt[i - 1];
    for (int i = 0; i < n; ++i)
        SA[--Cnt[Str[i]]] = i;
    Rank[SA[0]] = 0;
    int Classes = 1;
    for (int i = 1; i < n; ++i)
    {
        if (Str[SA[i]] != Str[SA[i - 1]])
            Classes++;
        Rank[SA[i]] = Classes - 1;
    }

    //Implementar o Radix Sort
    //Pra evitar o uso da sort() da STL
    vi TempSA(n), TempRank(n);
    for (int h = 0; (1 << h) < n; ++h)
    {
        for (int i = 0; i < n; ++i)
        {
            TempSA[i] = SA[i] - (1 << h);
            if (TempSA[i] < 0)
                TempSA[i] += n;
        }
        fill(Cnt.begin(), Cnt.begin() + Classes, 0);
        for (int i = 0; i < n; ++i)
            Cnt[Rank[TempSA[i]]]++;
        for (int i = 1; i < Classes; ++i)
            Cnt[i] += Cnt[i - 1];
        for (int i = n - 1; i >= 0; --i)
            SA[--Cnt[Rank[TempSA[i]]]] = TempSA[i];
        TempRank[SA[0]] = 0;
        Classes = 1;
        for (int i = 1; i < n; ++i)
        {
            ii Cur = { Rank[SA[i]], Rank[(SA[i] + (1 << h)) % n] };
            ii prev = { Rank[SA[i - 1]], Rank[(SA[i - 1] + (1 << h)) % n] };
            if (Cur != prev)
                ++Classes;
            TempRank[SA[i]] = Classes - 1;
        }
        Rank.swap(TempRank);
    }

    //SA.erase(SA.begin());
    return SA;
}

vi build_LCP(string& Str, vi SA)
{
    int n = Str.length();
    vi R(n, 0), LCP(n - 1, 0);
    for (int i = 0; i < n; ++i) R[SA[i]] = i;
    int K = 0;
    for (int i = 0; i < n; ++i)
    {
        if (R[i] != n - 1)
        {
            int j = SA[R[i] + 1];
            while (Str[i + K] == Str[j + K])
                ++K;
            LCP[R[i]] = K;
            if (K)
                --K;
        }
    }

    return LCP;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string Str, Aux;
    cin >> Str;
    Str = Str + '$';

    vi Alpha(27, 0);
    vi SuffixArr = build(Str);
    //printf("Suffix:\n");
    //for (int i : SuffixArr)
    //    printf("%d ", i);

    int N = Str.size();
    vi LCP = build_LCP(Str, SuffixArr);
    for (int i = 1; i < N; i++) //Quantidade substrings, que inicia com cada letra, distintas
        Alpha[Str[SuffixArr[i]] - 'a'] += N - 1 - SuffixArr[i] - LCP[i - 1];
    //printf("\nALPHA:\n");
    printf("%d", Alpha[0]);
    for (int i = 1; i < 26; i++)
        printf(" %d", Alpha[i]);
    printf("\n");

    return 0;
}