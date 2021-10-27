#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

typedef pair<int, int> ii;
typedef vector< int > vi;
typedef vector<pair< int, pair<int, int>>> viii;

int main()
{
	vi Vet;
	viii Vet2, Vet3;
	int Ri, Ei;
	int N; scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &Ri, &Ei);
		Vet.push_back(1);
		Vet2.push_back(make_pair(i, make_pair(Ri, Ei)));
	}
	cin.ignore();
	string Str; getline(cin, Str);
	int K = N;
	long long Tam = Str.size();
	while (K > 1)
	{
		Vet3.clear();
		for (int i = 0; i < K; i += 2)
		{
			if ((Vet2[i].s.f + Vet2[i].s.s * (Str.size())) <= (Vet2[i + 1].s.f + Vet2[i + 1].s.s * (Str.size())))
			{
				Vet3.push_back(Vet2[i]);
				Vet[Vet2[i].f]++;
			}
			else
			{
				Vet3.push_back(Vet2[i + 1]);
				Vet[Vet2[i + 1].f]++;
			}
		}
		Vet2 = Vet3;
		Tam += Tam;
		K = K / 2;
	}
	for (int i = 0; i < Vet.size() - 1; i++)
		printf("%d ", Vet[i]);
	printf("%d\n", Vet[Vet.size() - 1]);
}