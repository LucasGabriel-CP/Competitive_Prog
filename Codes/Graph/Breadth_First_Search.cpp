void BFS(vvi& AdjList, int N, int Source, int D) //Para usar peso, Adjlist tem que ser com pair
{
    queue<int> myQueue;
    vector<int> Visit(N);
    vi Dist(N), Parent(N);

    myQueue.push(Source);
    Visit[Source] = true;
    Parent(N) = -1;
    while (!myQueue.empty())
    {
        int v = myQueue.front();
        myQueue.pop();
        for (int u : AdjList[v])
        {
            if (!Visit[u])
            {
                Visit[u] = true;
                myQueue.push(u);
                Dist[u] = Dist[v] + 1;
                Parent[u] = v;
            }
        }
        
    }
    RestorePath(Visit, Parent, Source, D);
}

void RestorePath(vi& Visit, vi& Parent, int s, int u)
{
    if (!Visit[u])
    {
        printf("No Path.\n");
    }
    else
    {
        vi path;
        for (int v = u; v != -1; v = Parent[v])
            path.push_back(v);
        reverse(path.begin(), path.end());
        printf("Path %d-%d: ", s, u);
        for (int v : path)
            printf("%d ", v);
        printf("\n");
    }
}