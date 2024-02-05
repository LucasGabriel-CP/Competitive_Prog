/*
* Source: https://github.com/tdas0/lib/blob/master/library/Graph/SCC.cpp
* Complexity: O(|V|)
*/

struct SCC {
    std::vector<std::vector<int>> g, comps;
    std::vector<int> val, z, cont, comp;
    int Time = 0, ncomps = 0 , n; 
    SCC(std::vector<std::vector<int>> _g, int _n)
        : n(_n), g(_g), val(n+1, 0), comp(n+1, -1) { }
    int dfs(int j) {
        int low = val[j] = ++Time, x ; z.push_back(j);
        for (auto e: g[j]) {
            if(comp[e] < 0) {
                low = std::min(low, val[e] ?: dfs(e));
            }
        }
        if (low == val[j]) {
            do {
                x = z.back() ; z.pop_back();
                comp[x] = ncomps;
                cont.push_back(x);
            } while(x != j);
            comps.push_back(cont), cont.clear();
            ncomps++;
        }
        return val[j] = low;
    }

    void scc() {
        val.assign(n+1,0); comp.assign(n+1, -1);
        Time = ncomps = 0 ;
        for (int i = 1; i <= n; i++) {
            if(comp[i] < 0) {
                dfs(i);
            }
        }
    }

    std::vector<std::vector<int>> DAG() {// sem arestas repetidas
        std::vector<std::vector<int>> dag(n+1);
        val.assign(n+1,-1);

        for(int i=0;i<ncomps;i++) {
            for(auto v : comps[i]) {
                for(auto to : g[v]) {
                    if(val[to] == -1 && comp[to] != i) {
                        val[to] = 1;
                        dag[i].push_back(comp[to]);
                    }
                }
            }
            for(auto v : comps[i]) {
                for(auto to : g[v]) {
                    val[to] = -1;
                }
            }
        }
        return dag;
    }

    // representante da componente c (c < ncomps):
    int repre(int c) {
        return comps[c][0];
    }
};