#include <bits/stdc++.h>

using namespace std;
#define isvalid(a_, b_, n_, m_) (a_ >= 0 && a_ < n_ && b_ >= 0 && b_ < m_)

int x[6] = {-1, -1, 0, 0, 1, 1};
int y[6] = {-1, 0, -1, 1, 0, 1}, n;

char matrix[205][205];

bool bfs(int oi, int oj, char tipo){
	queue<pair<int, int>> q;
	q.push({oi, oj});
	matrix[oi][oj] = 'v';
	while(!q.empty()){
		pair<int, int> u = q.front();
		q.pop();
		if (tipo == 'b' && u.first == n-1) return true;
		else if (tipo == 'w' && u.second == n-1) return true;
		for (int i = 0; i < 6; ++i){
			int vi = u.first + x[i], vj = u.second + y[i];
			if (isvalid(vi, vj, n, n)){
				if (matrix[vi][vj] != tipo) continue;
				matrix[vi][vj] = 'v';
				q.push({vi, vj});
			}
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int c = 1;
	while(cin >> n, n){
		for (int i = 0; i < n; ++i) cin >> matrix[i];
		int b, w; b = w = 0;
		for (int i = 0; i < n;++i){
			if (matrix[0][i] == 'b' && bfs(0, i, 'b')){ b = 1; break; }
			if (matrix[i][0] == 'w' && bfs(i, 0, 'w')){ w = 1; break; }
		}
		cout << c++ << ' ' << (b > w ? 'B' : 'W') << '\n';
	}
}
