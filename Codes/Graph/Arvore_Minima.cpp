#include<bits/stdc++.h>
const int maxn = 1e5;

struct aresta{
	int a, b, p;
	aresta(){}
	aresta(int a, int b, int p){a = a; b = b; p = p;}
};
bool Comp(aresta a, aresta b) { return a.p < b.p; }

int pai[maxn], Rank[maxn];
std::vector<aresta> Lis;
std::vector<int> Ans;

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
	std::cin >> n;
	for	(int i = 0; i < n; i++) pai[i] = i, Rank[i] = 1;
	for	(int i = 0; i < m; i++){
		scanf("%d %d %d", &Hm.a, &Hm.b, &Hm.p);  //Adiciona a aresta a->b com peso p
		Lis.push_back(Hm);
	}
	sort(Lis.begin(), Lis.end(), Comp);
	std::vector<aresta> Ans;
	int S = 0;
	for	(int i = 0; i < m; i++){
		int X = Lis[i].a;
		int Y = Lis[i].b;
		int P = Lis[i].p;
		if	(find_parent(X) != find_parent(Y)){
			Ans.push_back(Lis[i]);
			S += P;
			unir(X,Y);
		}
	}
	printf("Ans: %d\n", S);
	for	(int i = 0; i < Ans.size(); i++)
		printf("Aresta: %d - %d | Peso: %d\n", Ans[i].a, Ans[i].b, Ans[i].p);
}