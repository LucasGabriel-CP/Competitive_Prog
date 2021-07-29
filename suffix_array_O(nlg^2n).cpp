#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <stack>
#include <list>
#include <limits.h>
#include <string.h>
#include <iomanip>

using namespace std;

#define pi 3.141592653589793
#define eulerconstant 0.577215664901532
#define sz 550
#define f first
#define s second
#define inf 1000000000
#define inf64 1000000000000000000

typedef pair<int, int> ii;
typedef pair<char, int> ci;
typedef pair<string, int> si;
typedef vector< int > vi;
typedef vector< char > vc;
typedef vector<pair<int, int>> vii;
typedef vector<pair< int, pair<int, int>>> viii;
typedef vector<vector<int>> vvi;
typedef long long ll;

int comp(vi R, int i, int j, int p) //p = 2^(k-1)
{
    if (i == j)
        return 0;
    if (R[i] != R[j])
        return R[i] - R[j];
    return R[i + p] - R[j + p];
}

vector<int> build(string& Str)  //Construção do Array
{
    int n = Str.length();
    vi SA(n), R(n), Temp(n);
    for (int i = 0; i < n; ++i)
    {
        SA[i] = i;
        R[i] = Str[i];
    }
    for (int p = 1; p < n; p *= 2)
    {
        sort(SA.begin(), SA.end(), [&](int i, int j) {  return comp(R, i, j, p) < 0 ? 1 : 0; });
        Temp[SA[0]] = 0;
        for (int i = 1, x = 0; i < n; ++i)
        {
            if (comp(R, SA[i], SA[i - 1], p) != 0)
                ++x;
            Temp[SA[i]] = x;
        }
        R = Temp;
    }

    SA.erase(SA.begin());
    return SA;
}

vi build_LCP(string& Str, vi SA) //Longest Common Prefix (precisa apagar a linha 67 pra funcionar perfeitamente)
{
    int n = Str.length();
    vi R(n), LCP(n);
    for (int i = 0; i < n; ++i) R[SA[i]] = i;
    int K = 0;
    for (int i = 0; i < n; ++i)
    {
        if (i != n - 1)
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
    string Str = "banana";
    Str += '$';
    vi SuffixArr = build(Str);
    for (int i : SuffixArr)
        printf("%d\n", i);
    return 0;
}