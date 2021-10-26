#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
typedef pair<int, int> ii;

int p[550];

void Union_Init(int N)
{
    for (int i = 0; i <= N; i++)
        p[i] = i;
}

int Union_find(int at)
{
    if (p[at] == at)
        return at;
    return p[at] = Union_find(p[at]);
}

void Union_set(int a, int b)
{
    a = Union_find(a);
    b = Union_find(b);
    if (a != b)
        p[a] = b;
}

int main()
{
    int N;
    int T; scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &N);
        priority_queue < pair<double, ii > > q;
        vector<pair<float, float>> Id;

        for (int i = 0; i < N; i++)
        {
            float x, y;
            scanf("%f %f", &x, &y);
            Id.push_back({ x, y });
        }
        int Count = -1;
        for (int i = 0; i < Id.size(); i++)
        {
            Count++;
            int Count2 = Count;
            for (int j = i + 1; j < Id.size(); j++)
            {
                Count2++;
                double z = sqrt((Id[j].f - Id[i].f) * (Id[j].f - Id[i].f) + (Id[j].s - Id[i].s) * (Id[j].s - Id[i].s));
                q.push({ -z, {Count, Count2} });
            }
        }

        Union_Init(N);
        double custo_melhorado = 0.0;
        while (!q.empty())
        {
            int a = Union_find(q.top().second.first);
            int b = Union_find(q.top().second.second);

            if (a != b) {
                Union_set(a, b);
                custo_melhorado += -q.top().first;
            }
            q.pop();
        }

        printf("%.2lf\n", custo_melhorado / 100);
    }
}