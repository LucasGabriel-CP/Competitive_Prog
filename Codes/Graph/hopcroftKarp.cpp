#include <bits/stdc++.h>

/*
* Source: kactl
* Complexity: O(sqrt(|V|) * |E|)
* Description: Fast bipartite matching algorithm. Graph g should be a list
*   of neighbors of the left partition, and btoa should be a vector full of -1’s of
*   the same size as the right partition. Returns the size of the matching. btoa[i]
*   will be the match for vertex i on the right side, or −1 if it’s not matched.
*/

bool dfs(int a, int L, std::vector<std::vector<int>> &g, std::vector<int>& btoa,
        std::vector<int>& A, std::vector<int>& B) {
    if (A[a] != L) return false;
    A[a] = -1;
    for (int b: g[a]) {
        if (B[b] == L + 1) {
            B[b] = 0;
            if (btoa[b] == -1 || dfs(btoa[b], L + 1, g, btoa, A, B)) {
                return btoa[b] = a, true;
            }
        }
    }
    return false;
}

int hopcroftKarp(std::vector<std::vector<int>>& g, std::vector<int>& btoa) {
    int ans = 0;
    std::vector<int> A((int)g.size()), B((int)btoa.size()), cur, nxt;
    while (true) {
        std::fill(A.begin(), A.end(), 0);
        std::fill(B.begin(), B.end(), 0);
        cur.clear();
        for (int a: btoa) {
            if (a != -1) {
                A[a] = -1;
            }
        }
        for (int i = 0; i < (int)g.size(); i++) {
            if (!A[i]) cur.push_back(i);
        }
        for (int lay = 1; ; lay++) {
            bool is_last = false;
            nxt.clear();
            for (int a: cur) {
                for (int b: g[a]) {
                    if (btoa[b] == -1) {
                        B[b] = lay;
                        is_last = true;
                    }
                    else if (btoa[b] != a && !B[b]) {
                        B[b] = lay;
                        nxt.push_back(btoa[b]);
                    }
                }
            }
            if (is_last) break;
            if (nxt.empty()) return ans;
            for (int a: nxt) A[a] = lay;
            std::swap(cur, nxt);
        }
        for (int i = 0; i < (int)g.size(); i++) {
            ans += dfs(i, 0, g, btoa, A, B);
        }
    }
    assert(false);
}