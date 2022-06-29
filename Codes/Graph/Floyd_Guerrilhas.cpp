const int inf = 1e9;
int n;

void Floyd(vector<vector<int>> Matrix){
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (Matrix[i][k] < inf && Matrix[k][j] < inf)
                    Matrix[i][j] = min(Matrix[i][j], Matrix[i][k] + Matrix[k][j]);
            }
        }
    }
}

void FloydFloat(vector<vector<float>> Matrix){
    for (int k = 0; k < n; ++k){
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                if (Matrix[i][k] < inf && Matrix[k][j] < inf)
                    Matrix[i][j] = Matrix[i][j] - 1e-9 > Matrix[i][k] + Matrix[k][j] ? Matrix[i][k] + Matrix[k][j] : Matrix[i][j];
            }
        }
    }
}
