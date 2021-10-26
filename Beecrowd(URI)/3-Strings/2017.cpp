#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define inf 1000000000

typedef pair<int, int> ii;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string Str, Str2;
    int N, Count, Tam;
    ii Menor = { 0, inf };
    cin >> Str >> N;
    Tam = (int)Str.size();
    for (int i = 0; i < 5; i++)
    {
        Count = 0;
        cin >> Str2;
        for (int i = 0; i < Tam && Count < Menor.s; i++)
            if (Str[i] != Str2[i])
                Count++;
        if (Count < Menor.s)
            Menor = { i + 1, Count };
    }
    if (Menor.f <= N)
        cout << Menor.f << '\n'
        << Menor.s << '\n';
    else
        cout << -1 << '\n';

    return 0;
}