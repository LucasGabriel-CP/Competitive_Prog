#include <bits/stdc++.h>

using namespace std;

struct Predio
{
	int l, h, r;
};

struct SkyLine
{
	int x, h;
};

void AddCord(vector<SkyLine>& S, int X, int H)
{
	if (S.empty())
	{
		S.push_back({ X, H });
		return;
	}
	if (S.back().h != H && S.back().x == X)
	{
		S.back().h = max(H, S.back().h);
		return;
	}
	if (S.empty() || S.back().h != H)
		S.push_back({ X, H });
}

vector<SkyLine> MergePredio(vector<SkyLine>& S1, vector<SkyLine>& S2)
{
	vector<SkyLine> Ans;
	int H1, H2;
	int CountS1, CountS2;
	CountS1 = CountS2 = H1 = H2 = 0;

	while (CountS1 < (int)S1.size() && CountS2 < (int)S2.size())
	{
		if (S1[CountS1].x < S2[CountS2].x)
		{
			H1 = S1[CountS1].h;
			AddCord(Ans, S1[CountS1].x, max(H1, H2));
			CountS1++;
		}
		else
			if (S1[CountS1].x == S2[CountS2].x)
			{
				if (S1[CountS1].h > S2[CountS2].h)
				{
					H1 = S1[CountS1].h;
					AddCord(Ans, S1[CountS1].x, H1);
					CountS1++;
				}
				else
				{
					H1 = S1[CountS1].h == S2[CountS2].h ? S1[CountS1].h : H1;
					H2 = S2[CountS2].h;
					AddCord(Ans, S1[CountS1].x, H2);
					CountS2++;
				}
			}
			else
			{
				H2 = S2[CountS2].h;
				AddCord(Ans, S2[CountS2].x, max(H1, H2));
				CountS2++;
			}
	}
	while (CountS1 < (int)S1.size())
	{
		AddCord(Ans, S1[CountS1].x, S1[CountS1].h);
		CountS1++;
	}
	while (CountS2 < (int)S2.size())
	{
		AddCord(Ans, S2[CountS2].x, S2[CountS2].h);
		CountS2++;
	}

	return Ans;
}

vector<SkyLine> buildSkyLine(vector<Predio> at, int Beg, int End)
{
	if (Beg == End)
	{
		return { { at[Beg].l, at[Beg].h }, { at[Beg].r, 0 } };
	}

	vector<SkyLine> S1 = buildSkyLine(at, Beg, (Beg + End) / 2);
	vector<SkyLine> S2 = buildSkyLine(at, (Beg + End) / 2 + 1, End);

	return MergePredio(S1, S2);
}

int main()
{
	vector<Predio> P;
	int L, H, R;
	while (cin >> L >> H >> R)
	{
		P.push_back({ L, H, R });
	}

	vector<SkyLine> Res(2);
	Res = buildSkyLine(P, 0, (int)P.size() - 1);
	cout << Res[0].x << ' ' << Res[0].h;
	for (int i = 1; i < (int)Res.size(); i++)
		cout << " " << Res[i].x << ' ' << Res[i].h;
	cout << "\n";

	return 0;
}