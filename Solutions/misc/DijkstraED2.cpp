#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define inf (int)1e9
#define inf64 (int)4e18

typedef pair<int, int> ii;
typedef pair<int, pair<int, int>> iii;
typedef pair<char, int> ci;
typedef pair<string, int> si;
typedef pair<int, string> is;
typedef vector< int > vi;
typedef vector< char > vc;
typedef vector<pair<int, int>> vii;
typedef vector<pair< int, pair<int, int>>> viii;
typedef vector<vector<int>> vvi;
typedef vector<vector<pair<int, int>>> vvii;

struct Heap{
    int n, Size;
    vii Vet;
    vi Idx;
    Heap(int n_){
        n = n_;
        Size = 0;
        Vet.resize(n);
        Idx.resize(n);
    }
    bool Empty(){
        return Size == 0;
    }
    void InsertHeap(int val, int v){
        Vet[Size++] = {val, v};
        int id = Size - 1;
        Idx[v] = id;
        while(id && Vet[id/2].f > Vet[id].f){
            std::swap(Idx[Vet[id/2].s], Idx[Vet[id].s]);
            std::swap(Vet[id/2], Vet[id]);
            id /= 2;
        }
    }
    void Init(vii &arr){
        for (int i = 0; i < (int)arr.size(); ++i){
            InsertHeap(arr[i].f, arr[i].s);
        }
    }
    void Heapify(int N, int id = 0){
        int l = 2 * id + 1, highest = id;
        int r = l + 1;
        if (l >= N) return;
        if (Vet[l] > Vet[highest]) highest = l;
        if (r < N && Vet[r] > Vet[highest]) highest = r;
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
    Dist.resize(n);
    Heap myPq(n);
    myPq.Init(AdjList[o]);
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

    return 0;
}
