#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ll Val;
    long M, N;
    while (scanf("%ld %ld", &N, &M) != EOF && N && M)
    {
        map<long long, vector<long> > myMap;
        for (long i = 0; i < N; i++)
        {
            scanf("%lld", &Val);
            myMap[Val].push_back(i + 1);
        }
        for (long i = 0; i < M; i++)
        {
            scanf("%ld %lld", &N, &Val);
            if (myMap.count(Val))
            {
                if (myMap[Val].size() < N)
                    printf("0\n");
                else
                {
                    printf("%ld\n", myMap[Val][N - 1]);
                }
            }
            else
            {
                printf("0\n");
            }
        }
    }
}