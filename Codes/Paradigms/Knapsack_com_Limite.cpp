using namespace std;

int n;
int value[60], weight[60], dp[60][61];
string nomes[60];

int f(int at, int w){
	if (at >= n) return 0;
	if (dp[at][w] != -1) return dp[at][w];
	if (w < weight[at]) return dp[at][w] = f(at + 1, w);
	int p1 = value[at] + f(at + 1, w - weight[at]);
	int p2 = f(at + 1, w);
	return dp[at][w] = max(p1, p2);
}

vector<string> resp;
void rec(int at, int w){
	if (at >= n)        return;
	if (w < weight[at]) return rec(at + 1, w);
	int p1 = value[at] + f(at + 1, w - weight[at]);
	int p2 = f(at + 1, w);
	if (f(at, w) == p1){
		resp.push_back(nomes[at]);
		return rec(at + 1, w - weight[at]);
	}
	else return rec(at + 1, w);
}

int main(){
	int c;
	scanf("%d", &n);
	scanf("%d", &c);
	int aux = 0;
	for (int i = 0; i < n; i++) {
		int v, p, qt;
		string nome;
		scanf("%d %d %d", &v, &p, &qt);
		cin >> nome;
		int pot = 1;
		while(qt > pot) {
			value[aux] = v * pot;
			weight[aux] = p * pot;
			nomes[aux] = nome;
			aux++;
			qt -= pot;
			pot *= 2;
		}
		value[aux] = v * qt;
		weight[aux] = p * qt;
		aux++;
	}
	n = aux;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= c; j++)
			dp[i][j] = -1;
	printf("%d\n", f(0, 50));
	rec(0, 50);
	for (int i = 0; i < resp.size(); i++)
		printf("%s\n", resp[i].c_str());
	printf("\n");
}
