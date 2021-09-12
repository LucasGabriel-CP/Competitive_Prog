//Exemplo de dfs (para componentes conexos) usando o exercício URI 1706

char Let[1050];
bool Visit[sz]; //Vetor de visitados
vi AdjList[sz]; //Lista de adjacêncai

int Bes(int Cur)
{
    Visit[Cur] = true; //Visito o vértice
    int Ans = 0;
    if  (Let[Cur] == 'B')
        Ans = 1;
    for (int to : AdjList[Cur]) //Chamo a função pra cada vértice adjacente
    {
        if  (!Visit[to])
            Ans += Bes(to);
    }
    return Ans;
}

int main()
{
    int N, M;
    while(scanf("%d %d", &N, &M) != EOF)
    {
        bool Da = true;
        for (int i = 0; i < N; i++) AdjList[i].clear(); //Limpar cada lista
        for (int i = 0; i < N; i++) Visit[i] = 0;		//Atribuir falso a todos vértice

        for (int i = 0; i < N; i++)
            scanf(" %c", &Let[i]); 

        for (int i = 0; i < M; i++)
        {
            int a, b; scanf("%d %d", &a, &b);
            a--;
            b--;
            AdjList[a].push_back(b);	//adiciono vértice a<->b
            AdjList[b].push_back(a);
        }
        for (int i = 0; i < N; i++)
        {
            if  (!Visit[i])
            {
                int Count = Bes(i); //Chamo a dfs
                if  (Count % 2)
                    Da = false;
            }
        }
        if  (Da)
            printf("Y\n");
        else
            printf("N\n");
    }
}