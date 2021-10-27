#include <bits/stdc++.h>

using namespace std;

typedef vector< int > vi;

vi Vet;

struct Node {
	Node* left = NULL;
	Node* right = NULL;
	int Key;
};

struct Tree {
	Node* Root = NULL;
	void insert(Node* P, Node** R, int Val)
	{
		if (!(*R))
			*R = P;
		else
			if ((*R)->Key > Val)
				insert(P, &(*R)->left, Val);
			else
				insert(P, &(*R)->right, Val);
	}
	void PreOrd(Node* P)
	{
		if (P)
		{
			Vet.push_back(P->Key);
			PreOrd(P->left);
			PreOrd(P->right);
		}
	}
	void BFS(Node* P, int N)
	{
		queue<Node*> q;
		q.push(P);
		while (!q.empty())
		{
			Node* v = q.front();
			Vet.push_back(v->Key);
			q.pop();
			if (v->left)
				q.push(v->left);
			if (v->right)
				q.push(v->right);
		}
	}
};

int main()
{
	Node* No;
	int N; scanf("%d", &N);
	for (int C = 1; C <= N; C++)
	{
		Tree T;
		int Tam; scanf("%d", &Tam);
		while (Tam--)
		{
			int K; scanf("%d", &K);
			No = new Node;
			No->Key = K;
			T.insert(No, &T.Root, K);
		}
		T.BFS(T.Root, N);
		Tam = (int)Vet.size() - 1;
		printf("Case %d:\n", C);
		for (int i = 0; i < Tam; i++)
			printf("%d ", Vet[i]);
		printf("%d\n\n", Vet[Tam]);
		Vet.clear();
	}
}