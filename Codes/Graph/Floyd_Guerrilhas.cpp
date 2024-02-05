/*
	(ˆ ڡ ˆ)yum!
*/

const int inf = 1e9;
int n;

void Floyd(std::vector<std::vector<int>> Matrix){
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (Matrix[i][k] < inf && Matrix[k][j] < inf)
                    Matrix[i][j] = std::min(Matrix[i][j], Matrix[i][k] + Matrix[k][j]);
            }
        }
    }
}

void FloydFloat(std::vector<std::vector<float>> Matrix){
    for (int k = 0; k < n; ++k){
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                if (Matrix[i][k] < inf && Matrix[k][j] < inf)
                    Matrix[i][j] = Matrix[i][j] - 1e-9 > Matrix[i][k] + Matrix[k][j] ? Matrix[i][k] + Matrix[k][j] : Matrix[i][j];
            }
        }
    }
}
