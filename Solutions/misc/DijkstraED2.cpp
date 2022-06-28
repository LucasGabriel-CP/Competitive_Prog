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
        Size = 0;
        Vet.resize(n, {inf, -1});
        Idx.resize(n, -1);
    }

    bool empty(){ return Size == 0; }

    void Heapify(int id = 0){
        int l = 2 * id + 1, r = 2 * id + 2, smallest = id;
        if (l >= Size) return;
        if (Vet[l].f < Vet[smallest].f)
            smallest = l;
        if (r < Size && Vet[r].f < Vet[smallest].f)
            smallest = r;
        if (smallest != id){
            Idx[Vet[smallest].s] = id;
            Idx[Vet[id].s] = smallest;
            std::swap(Vet[id], Vet[smallest]);
            Heapify(smallest);
        }
    }

    ii ExtractHeap(){
        if (!Size) abort();
        ii Temp = Vet[0];
        --Size;
        Idx[Vet[0].s] = Size;
        Idx[Vet[Size].s] = 0;
        std::swap(Vet[0], Vet[Size]);
        Vet[Size].f = inf;
        Heapify();
        return Temp;
    }

    void DecreaseKey(int val, int v){
        if (Idx[v] == -1){
            Vet[Size] = {val, v};
            Idx[v] = Size;
            ++Size;
        }
        int id = Idx[v];
        Vet[id].f = val;
        while(id && Vet[(id-1)/2].f > Vet[id].f){
            Idx[Vet[(id-1)/2].s] = id;
            Idx[Vet[id].s] = (id-1)/2;
            std::swap(Vet[(id-1)/2], Vet[id]);
            id = (id-1)/2;
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
