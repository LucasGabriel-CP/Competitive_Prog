#define MAX_N 100005
#define Mid ((l + r) >> 1)

typedef vector< int > vi;
typedef long long ll;

/*
* Using a index array sorted by Vet[a] < Vet[b]
* Find the kth value on range [i,j]
*/
int N, indx[MAX_N];
vi Seg[4 * MAX_N]; //4*MAX_N -> Number of nodes
ll Vet[MAX_N];

void build(int id = 1, int l = 0, int r = N)
{
    if (r - l < 2)  //Range for [l, r)
    {
        Seg[id].push_back(indx[l]);  //insert index on the interval
        return;
    }
    build(2 * id, l, Mid);
    build(2 * id + 1, Mid, r);
    //Merge the node
    merge(Seg[2 * id].begin(), Seg[2 * id].end(), Seg[2 * id + 1].begin(), Seg[2 * id + 1].end(), back_inserter(Seg[id]));
}

int Solve(int i, int j, int k, int l = 0, int r = N, int id = 1)
{
    if (r - l < 2)
        return Seg[id][0];  //It'll return the index on the node
    //Amount of indexes on the range [i, j]
    int pj = upper_bound(Seg[2 * id].begin(), Seg[2 * id].end(), j) - Seg[2 * id].begin();
    int pi = lower_bound(Seg[2 * id].begin(), Seg[2 * id].end(), i) - Seg[2 * id].begin();
    int diff = pj - pi;
    if (diff >= k)  //if diff is bigger/equal, element is on the left
        return Solve(i, j, k, l, Mid, 2 * id);
    return Solve(i, j, k - diff, Mid, r, 2 * id + 1); //element on the right
}

//query for numbers lower than x
//build around Vet[i] values insted
int query(int i, int j, int x, int l = 0, int r = N, int id = 1)
{
    if (r < i || j < l)
        return 0;
    if (i <= l && r <= j)   //upper_bound if <=x
        return lower_bound(Seg[id].begin(), Seg[id].end(), x) - Seg[2 * id].begin();
    return query(i, j, l, Mid, 2 * id) + query(i, j, Mid, r, 2 * id + 1);
}

int main()
{
    sort(indx, indx + N, [](int a, int b) {return Vet[a] < Vet[b]; });
    build();
    int L, R, Kth;
    int Elem = Solve(L - 1, R, Kth);
    printf("%lld\n", Vet[Elem]);

    return 0;
}