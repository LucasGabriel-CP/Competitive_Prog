void Floyd(vvf Matrix)
{
    for (int k = 0; k < N; ++k) {
			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < N; ++j) {
					if (Matrix[i][k] < inf && Matrix[k][j] < inf)
						Matrix[i][j] = min(Matrix[i][j], Matrix[i][k] + Matrix[k][j]);
				}
			}
		}
}


void FloydFloat(vvf Matrix) //Corrgir erro de imprecisão
{
    for (int k = 0; k < N; ++k) {
			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < N; ++j) {
					if (Matrix[i][k] < inf && Matrix[k][j] < inf)
						Matrix[i][j] = Matrix[i][j] - 1e-9 > Matrix[i][k] + Matrix[k][j] ? Matrix[i][k] + Matrix[k][j] : Matrix[i][j];
				}
			}
		}
}