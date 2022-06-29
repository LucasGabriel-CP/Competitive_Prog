const int MAXN = 1e5;

struct aresta{
	int a, b, p;
	aresta(){}
	aresta(int a, int b, int p){a = a; b = b; p = p;}
};
bool Comp(aresta a, aresta b) { return a.p < b.p; }

int pai[MAXN], Rank[MAXN];
vector<aresta> Lis;
vector<int> Ans;

int find_parent(int v){
    if (pai[v] == v)
        return v;
    return pai[v] = find_parent(pai[v]);
}

void unir(int u, int v){
    int x = find_parent(u);
    int y = find_parent(v);
    if (Rank[x] > Rank[y]){
        ++Rank[x];
        pai[y] = x;
    }
    else{
        ++Rank[y];
        pai[x] = y;
    }
}

int main(){
	aresta Hm;
	int n, m;
	cin >> n;
	for	(int i = 0; i < n; i++) pai[i] = i, Rank[i] = 1;
	for	(int i = 0; i < m; i++){
		scanf("%d %d %d", &Hm.a, &Hm.b, &Hm.p);  //Adiciona a aresta a->b com peso p
		Lis.push_back(Hm);
	}
	sort(Lis.begin(), Lis.end(), Comp);
	vector<aresta> Ans;
	int S = 0;
	for	(int i = 0; i < m; i++){
		int X = Lis[i].a;
		int Y = Lis[i].b;
		int P = Lis[i].p;
		if	(acha_pai(X) != acha_pai(Y)){
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
void Union_Init(int n){
	for (int i = 0; i <= n; i++)
		p[i] = i;
}

int Union_find(int at){
	if (p[at] == at)
		return at;

	return p[at] = Union_find(p[at]);
}

void Union_set(int a, int b){
	a = Union_find(a);
	b = Union_find(b);

	if (a != b)
		p[a] = b;
}

int main(){
	int m, n;

	while (cin >> n >> m && (n != 0 || m != 0)){
		int custo_atual = 0;

		priority_queue < pair<int, pair<int, int> > > q;

		// leitura
		for (int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			q.push(pair<int, pair<int, int> >(-z, pair<int, int>(x, y)));
			custo_atual += z;
		}

		Union_Init(n);

		int custo_melhorado = 0;
		while (!q.empty()){
			//descobrir o subconjunto do no 1
			int a = Union_find(q.top().second.first);
			//descobrir o subconjunto do no 2
			int b = Union_find(q.top().second.second);
			//se eles forem diferentes
			if (a != b){
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
