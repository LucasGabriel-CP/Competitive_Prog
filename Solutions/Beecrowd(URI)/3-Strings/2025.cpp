#include <bits/stdc++.h>

using namespace std;

typedef vector< int > vi;
typedef vector<vector<int>> vvi;

int LCSspaceOtm(string Str1, string Str2)
{
    int N = (int)Str1.size();
    int M = (int)Str2.size();
    int Ans = 0;
    vvi dp(2, vi(M + 1));

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (Str1[i - 1] == Str2[j - 1])
            {
                dp[i % 2][j] = dp[(i - 1) % 2][j - 1] + 1;
                if (dp[i % 2][j] > Ans)
                    Ans = dp[i % 2][j];
            }
            else
                dp[i % 2][j] = 0;
        }
    }

    return Ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N; cin >> N;
    string Str, Jo = "oulupukk";
    cin.ignore();
    while (N--)
    {
        getline(cin, Str);
        string Aux = "";
        for (int i = 0; i < Str.size(); i++)
        {
            if (Str[i] == ' ' || Aux.size() == 10)
            {
                if (Aux.size() < 10 || Aux.size() > 11 || (Aux.size() == 11 && Aux.back() != '.'))
                    cout << Aux << Str[i];
                else
                {
                    if (LCSspaceOtm(Jo, Aux) == 8)
                    {
                        cout << "Joulupukki";
                        if (Aux.size() == 11)
                            cout << '.';
                        if (Aux.size() != 9 && Str[i] == ' ')
                            cout << Str[i];
                    }
                    else
                    {
                        cout << Aux;
                        Aux = Str[i]; continue;
                    }
                }
                if (Aux.size() == 10 && Str[i] != ' ')
                    Aux = Str[i];
                else
                    Aux = "";
            }
            else
            {
                Aux += Str[i];
            }
        }
        if (Aux != "")
        {
            if (Aux.size() < 9 || Aux.size() > 11 || (Aux.size() == 11 && Aux.back() != '.'))
                cout << Aux;
            else
            {
                if (LCSspaceOtm(Jo, Aux) == 8)
                {
                    cout << "Joulupukki";
                    if (Aux.size() == 11)
                        cout << '.';
                    if (Aux.size() != 9 && Str.back() == ' ')
                        cout << Str.back();
                }
                else
                {
                    cout << Aux;
                }
            }
        }
        cout << '\n';
    }

    return 0;
}