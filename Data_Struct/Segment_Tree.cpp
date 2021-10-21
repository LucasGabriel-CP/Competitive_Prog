#define MAX_N 100005
#define Mid ((l + r) >> 1)
typedef int no;

/*
* Find the sum on a interval and other stuff
*/
int N, Vet[MAX_N], Seg[4 * MAX_N];

no Modify(no a, no b)   //Function to do what I want
{
    return a + b;
}

no build(int id = 1, int l = 0, int r = N)
{
    if (r - l < 2)  //[l, r)
        return Seg[id] = Vet[l];  //insert value on the interval
    Seg[id] = Modify(build(2 * id, l, Mid), build(2 * id + 1, Mid, r));
}

no Update(int i, int x, int l = 0, int r = N, int id = 1)
{
    if (r < i || i < l)
        return Seg[id];
    if (r - l < 2)
        return Seg[id] = x; //Replace by x
    return Modify(Update(i, x, l, Mid, 2 * id), Update(i, x, Mid, r, 2 * id + 1));
}

int query(int i, int j, int l = 0, int r = N, int id = 1)
{
    if (r < i || j < l)
        return 0;   //Don't change the answer
    if (i <= l && r <= j)
        return Seg[id];
    return Modify(query(i, j, l, Mid, 2 * id), query(i, j, Mid, r, 2 * id + 1));
}