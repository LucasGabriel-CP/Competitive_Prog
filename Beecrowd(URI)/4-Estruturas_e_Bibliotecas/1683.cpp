#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll MaxTam(vector<long long> Hist, long N)
{
    stack<long long> myStack;
    ll MaiorArea = 0;
    ll Topo;
    ll AreaTop;
    long i = 0;
    while (i < N)
    {
        if (myStack.empty() || Hist[myStack.top()] <= Hist[i])
            myStack.push(i++);
        else
        {
            Topo = myStack.top();
            myStack.pop();
            AreaTop = Hist[Topo] * (myStack.empty() ? i : i - myStack.top() - 1);
            if (MaiorArea < AreaTop)
                MaiorArea = AreaTop;
        }
    }
    while (!myStack.empty())
    {
        Topo = myStack.top();
        myStack.pop();
        AreaTop = Hist[Topo] * (myStack.empty() ? i : i - myStack.top() - 1);
        if (MaiorArea < AreaTop)
            MaiorArea = AreaTop;
    }
    return MaiorArea;
}

int main()
{
    ll Val;
    long N;
    while (scanf("%ld", &N) != EOF && N)
    {
        vector<long long> Histo;
        for (long i = 0; i < N; i++)
        {
            scanf("%lld", &Val);
            Histo.push_back(Val);
        }
        printf("%lld\n", MaxTam(Histo, N));
    }
}