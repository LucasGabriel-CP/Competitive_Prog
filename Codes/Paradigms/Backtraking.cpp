using namespace std;

int matrix[8][8];
int di[8] = { 0, 1, 0,-1, -1, 1, 1, -1 };
int dj[8] = { 1, 0,-1, 0, 1, 1, -1, -1 };

bool checkQueen(int i, int j){
	for (int k = 0; k < 8; k++){
		int ni = i + di[k];
		int nj = j + dj[k];
		while (ni >= 0 && ni < 8 && nj >= 0 && nj < 8) {
			if (matrix[ni][nj] == 1)
				return false;
			ni = ni + di[k];
			nj = nj + dj[k];
		}
	}

	return true;
}

int cnt = 0;
void backtracking(int row){
	if (row == 8) {
		// sucesso
		cnt++;
		return;
	}
	for (int i = 0; i < 8; i++) {
		matrix[row][i] = 1;
		if (checkQueen(row, i))
			backtracking(row + 1);
		matrix[row][i] = 0;
	}
}
