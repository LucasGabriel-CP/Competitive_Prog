struct aresta
{
	int a, b, p;
};
bool Comp(aresta a, aresta b)	{ return a.p < b.p; }

int pai[sz];
int Rank[sz];
vector< aresta > Lis;
priority_queue< ii, vector<ii>, greater<ii> > myPq;

int acha_pai(int X)
{
	if	(pai[X] == X)
		return X;
	return pai[X] = acha_pai(pai[X]);
}

void unir(int X, int Y)
{
	X = acha_pai(X);
	Y = acha_pai(Y);
	if	(Rank[X] > Rank[Y])
	{
		pai[Y] = X;
		Rank[X]++;
	}
	else
	{
		pai[X] = Y;
		Rank[Y]++;
	}
}

int main()
{
	for	(int i = 0; i < 10; i++) pai[i]  = i;
	for	(int i = 0; i < 10; i++) Rank[i] = 1;
	aresta Hm;
	for	(int i = 0; i < 10; i++)
	{
		scanf("%d %d %d", &Hm.a, &Hm.b, &Hm.p);  //Adiciona a aresta a->b com peso p
		Lis.push_back(Hm);
	}
	sort(Lis.begin(), Lis.end(), Comp);
	
	vector< aresta > Ans;
	int S = 0;
	for	(int i = 0; i < 10; i++)
	{
		int X = Lis[i].a;
		int Y = Lis[i].b;
		int P = Lis[i].p;
		if	(acha_pai(X) != acha_pai(Y))
		{
			Ans.push_back(Lis[i]);
			S += P;
			unir(X,Y);
		}
	}
	printf("Ans: %d\n", S);
	for	(int i = 0; i < Ans.size(); i++)
		printf("Aresta: %d - %d | Peso: %d\n", Ans[i].a, Ans[i].b, Ans[i].p);
}

/*
* Outra forma
void Union_Init(int n)
{
	for (int i = 0; i <= n; i++)
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
	int m, n;

	while (cin >> n >> m && (n != 0 || m != 0))
	{
		int custo_atual = 0;

		priority_queue < pair<int, pair<int, int> > > q;

		// leitura
		for (int i = 0; i < m; i++)
		{
			int x, y, z;
			cin >> x >> y >> z;

			q.push(pair<int, pair<int, int> >(-z, pair<int, int>(x, y)));

			custo_atual += z;
		}

		Union_Init(n);

		int custo_melhorado = 0;
		while (!q.empty())
		{
			//descobrir o subconjunto do no 1
			int a = Union_find(q.top().second.first);

			//descobrir o subconjunto do no 2
			int b = Union_find(q.top().second.second);

			//se eles forem diferentes
			if (a != b) {
				//conecta
				Union_set(a, b);

				//contabiliza o custo
				custo_melhorado += -q.top().first;
			}

			q.pop();
		}

		int resp = custo_atual - custo_melhorado;

		cout << resp << endl;
	}
}
*/
