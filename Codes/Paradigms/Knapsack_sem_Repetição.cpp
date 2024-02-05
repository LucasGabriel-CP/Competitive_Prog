using namespace std;

#define MAX_N 10005
typedef vector< int > vi;
typedef vector<vector<int>> vvi;

//Top-Down approach
int Ans, N;
int Price[MAX_N], Peso[MAX_N];
int pd[MAX_N][100];
vi VetRec;

int Knap(int Ct, int W)
{
	if  (Ct >= N)
		return 0;
	if  (pd[Ct][W] != -1)
		return pd[Ct][W];
	if  (Peso[Ct] > W)
		return pd[Ct][W] = Knap(Ct + 1, W);

	int Op1 = Knap(Ct + 1, W);
	int Op2 = Price[Ct] + Knap(Ct + 1, W - Peso[Ct]);

	return pd[Ct][W] = max(Op1, Op2);
}

void Rec(int Ct, int W)
{
	if	(Ct >= N)
		return;
	if	(Peso[Ct] > W)
		return Rec(Ct +1, W);
	int Choice = Knap(Ct, W);
	int Op1 = Price[Ct] + Knap(Ct + 1, W - Peso[Ct]);
	int Op2 = Knap(Ct + 1, W);

	if	(Choice == Op1)
	{
		VetRec.push_back(Ct);
		return Rec(Ct + 1, W - Peso[Ct]);
	}
	else
		return Rec(Ct + 1, W);
}

//----------------------------------------------------------------------------------//
//Bottom-Up Approach
void Reconstruc(vvi& dp, vector< vector< bool > >& Keep, 
				vi& Pesos, vi& Valor, int N, int W)
{
	for (int i = N; i >= 0; --i)
	{
		if (Keep[i][W])
		{
			cout << "Item: " << i << ". Peso: " << Pesos[i - 1] 
				<< ". Valor: " << Valor[i - 1] << '\n';
			W -= Pesos[i - 1];
		}
	}
}

int Knapsack(int N, int W, vi& Pesos, vi& Valor)
{
	vvi dp(N + 1, vi(W + 1));
	vector< vector< bool > > Keep(N + 1, vector< bool >(W + 1));
	for (int i = 0; i <= W; ++i)
		dp[0][i] = 0;
	for (int i = 0; i <= N; ++i)
		dp[i][0] = 0;
	for (int k = 1; k <= N; ++k)
	{
		for (int d = 1; d <= W; ++d)
		{
			Keep[k][d] = Pesos[k - 1] <= d;
			if (!Keep[k][d])
				dp[k][d] = dp[k - 1][d];
			else
			{
				int Op = dp[k - 1][d - Pesos[k - 1]] + Valor[k - 1];
				if (Op > dp[k - 1][d])
				{
					Keep[k - 1][d] = false;
					Keep[k][d] = true;
					dp[k][d] = Op;
				}
				else
				{
					Keep[k][d] = false;
					dp[k][d] = dp[k - 1][d];
				}
			}
		}
	}

	// std::cout << "Matriz da pd:\n";
	// for (std::vector<int> i : dp)
	// {
	// 	for (int j : i)
	// 		std::cout << j << ' ';
	// 	std::cout << '\n';
	// }

	Reconstruc(dp, Keep, Pesos, Valor, N, W);

	return dp[N][W];	//Maior valor possível
}