#include <bits/stdc++.h>
#define f first
#define s second
#define inf (int)1e9
#define inf64 (int)4e18

typedef std::pair<int, int> ii;
typedef std::pair<int, std::pair<int, int>> iii;
typedef std::pair<char, int> ci;
typedef std::pair<std::string, int> si;
typedef std::pair<int, std::string> is;
typedef std::vector< int > vi;
typedef std::vector< char > vc;
typedef std::vector<std::pair<int, int>> vii;
typedef std::vector<std::pair< int, std::pair<int, int>>> viii;
typedef std::vector<std::vector<int>> vvi;
typedef std::vector<std::vector<std::pair<int, int>>> vvii;

struct Heap{
    int n, Size;
    vii Vet;
    vi Idx;
    Heap(int n_){
        n = n_;
        Size = n_;
        Vet.resize(n);
        Idx.resize(n + 1, -1);
        for (int i = 0; i < n; ++i)
            Vet[i].s = Idx[i] = i;
    }
    bool Empty(){
        return Size == 0;
    }
    void Heapify(int N, int id = 0){
        int l = 2 * id + 1, highest = id;
        int r = l + 1;
        if (l >= N) return;
        if (Vet[l].f > Vet[highest].f)
            highest = l;
        if (r < N && Vet[r].f > Vet[highest].f)
            highest = r;
        if (highest != id){
            std::swap(Idx[Vet[highest].s], Idx[Vet[id].s]);
            std::swap(Vet[id], Vet[highest]);
            Heapify(N, highest);
        }
    }
    ii ExtractHeap(){
        if (!Size) abort();
        ii Temp = Vet[0];
        --Size;
        std::swap(Idx[Vet[0].s], Idx[Vet[Size].s]);
        std::swap(Vet[0], Vet[Size]);
        Heapify(Size);
        return Temp;
    }
    void DecreaseKey(int val, int v){
        Vet[Idx[v]].f = val;
        int id = Idx[v];
        while(id && Vet[id/2].f > Vet[id].f){
            std::swap(Idx[Vet[id/2].s], Idx[Vet[id].s]);
            std::swap(Vet[id/2], Vet[id]);
            id /= 2;
        }
    }
};

int Dijkstra(vvii &AdjList, vi &Dist, int n, int o, int d){
    Dist.assign(n, inf);
    Heap myPq(n);
    myPq.DecreaseKey(0, o);
    Dist[o] = 0;
    while(!myPq.Empty()){
        ii u = myPq.ExtractHeap();
        for (ii it : AdjList[u.s]){
            int v = it.f;
            int w = it.s;
            if (Dist[v] > u.f + w){
                Dist[v] = u.f + w;
                myPq.DecreaseKey(Dist[v], v);
            }
        }
    }
    return Dist[d];
}

int main(){
	int n, m; std::cin >> n >> m;
	vvii AdjList(n, vii());
	vi Dist;
	for(int i = 0; i < m; ++i){
		int a, b, p; std::cin >> a >> b >> p;
		AdjList[a].push_back({b, p});
	}

	Dijkstra(AdjList, Dist, n, 0, 3);
	std::cout << Dist[3] << '\n';

    return 0;
}
