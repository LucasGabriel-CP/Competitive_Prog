#include <bits/stdc++.h>

using namespace std;

int Matrix[8][8], n, x[8] = {2, 2, -2, -2, 1, -1, 1, -1}, y[8] = {1, -1, 1, -1, 2, 2, -2, -2};

bool isvalid(int a, int b){
	return !(a < 0 || a >= 8 || b < 0 || b >= 8) && Matrix[a][b] == -1;
}

void Move(int a, int b, int da, int db){
	queue<pair<int, int>> myQ;
	myQ.push({a, b});
	Matrix[a][b] = 0;
	while(!myQ.empty() && Matrix[da][db] == -1){
		pair<int, int> u = myQ.front();
		myQ.pop();
		for (int i = 0; i < 8 && Matrix[da][db] == -1; ++i){
			int ai = u.first + x[i], bi = u.second + y[i];
			if (isvalid(ai, bi)){
				Matrix[ai][bi] = Matrix[u.first][u.second] + 1;
				myQ.push({ai, bi});
			}
		}
	}
}

string xx, yy;

void solve(){
	for (int i = 0; i < 8; ++i)
		for (int j = 0; j < 8; ++j)
			Matrix[i][j] = -1;
	int di, dj, oi, oj;
	oi = int(xx[0] - 'a');
	oj = int(xx[1] - '1');
	di = int(yy[0] - 'a');
	dj = int(yy[1] - '1');
	Move(oi, oj, di, dj);
	cout << "To get from " << xx << " to " << yy << " takes " << Matrix[di][dj] << " knight moves.\n";
}

int main(){
	while(cin >> xx >> yy){
		solve();
	}

	return 0;
}
