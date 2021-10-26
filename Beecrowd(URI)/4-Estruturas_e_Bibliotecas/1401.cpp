#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    forn(i, N)
    {
        string Letras;
        cin >> Letras;
        sort(Letras.begin(), Letras.end());
        do {
            cout << Letras << '\n';
        } while (next_permutation(Letras.begin(), Letras.end()));
        cout << '\n';
    }

    return 0;
}