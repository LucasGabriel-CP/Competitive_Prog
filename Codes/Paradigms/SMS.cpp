int RANGESUM(int n, vector<int> const& vet){
    int ans = 0, aux = 0;
    for (int i: vet){
        if (aux + i >= 0){
            aux += i;
            ans = max(aux, ans);
        }
        else aux = 0;
    }

	return ans;
}

//---------------------------------------------------------------------//
//Para Arrays 2D, [N x N]
//O(N^3) 1D PD + uso do Kadane's
int main(){
	int Matrix[101][101];	//Menor valor possível = -127
	int N;	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			scanf("%d", &Matrix[i][j]);
			if (j)
				Matrix[i][j] += Matrix[i][j - 1];	//Adiciona as colunas [i]
		}
	}

	int maxSub = -127 * 100 * 100;	//Armazenar o menor valor possível
	for (int l = 0; l < N; l++){
		for (int r = l; r < N; r++){
			int subRec = 0;
			for (int row = 0; row < N; row++){	//Calcular o máximo para aquela coluna
				if (l)
					subRec += Matrix[row][r] - Matrix[row][l - 1];
				else
					subRec += Matrix[row][r];
				//Implementação do Kadane
				if (subRec < 0)		//Resetar se negativo
					subRec = 0;
				maxSub = max(maxSub, subRec);
			}
		}
	}
	printf("%d\n", maxSub);

	return 0;
}

//-------------------------------------------------------------------//
//Uso de Força de Bruta
/*
int main()	//Somo todas uma por uma, O(N^6)
{
	scanf("%d", &N);
	for	(int i = 0; i < N; i++)
		for	(int j = 0; j < N; j++)
			scanf("%d", &Matrix[i][j]);

	maxSubRect = -127*100*100;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) // start coordinate
			for (int k = i; k < n; k++)
				for (int l = j; l < n; l++) {    // end coord
						subRect = 0;	// sum items in this sub-rectangle
					for (int a = i; a <= k; a++)
						for (int b = j; b <= l; b++)
						subRect += A[a][b];
					maxSubRect = max(maxSubRect, subRect);
				}

	printf("%d\n", maxSubRect);
	return 0;
}
*/
