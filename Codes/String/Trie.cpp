struct Trie {
	std::vector<std::vector<int>> to;
	std::vector<int> end, pref;
	int sigma; char norm;
	Trie(int sigma_=26, char norm_='a') : sigma(sigma_), norm(norm_) {
		to = {std::vector<int>(sigma)};
		end = {0}, pref = {0};
	}
	void insert(std::string const & s) {
		int x = 0;
		for(auto c : s) {
			int &nxt = to[x][c-norm];
			if(!nxt) {
				nxt = to.size();
				to.push_back(std::vector<int>(sigma));
				end.push_back(0), pref.push_back(0);
			}
			x = nxt, pref[x]++;
		}
		end[x]++;
	}
	void erase(std::string const & s) {
		int x = 0;
		for(char c : s) {
			int &nxt = to[x][c-norm];
			x = nxt, pref[x]--;
			if(!pref[x]) nxt = 0;
		}
		end[x]--;
	}
	int find(std::string const & s) {
		int x = 0;
		for(auto c : s) {
			x = to[x][c-norm];
			if(!x) return 0;
		}
		return x;
	}
	int count_pref(std::string const s) {
		return pref[find(s)];
	}
};