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
	void InOrd(Node* P)
	{
		if (P)
		{
			InOrd(P->left);
			Vet.push_back(P->Key);
			InOrd(P->right);
		}
	}
	void PosOrd(Node* P)
	{
		if (P)
		{
			PosOrd(P->left);
			PosOrd(P->right);
			Vet.push_back(P->Key);
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
		T.PreOrd(T.Root);
		Tam = (int)Vet.size() - 1;
		printf("Case %d:\nPre.: ", C);
		for (int i = 0; i < Tam; i++)
			printf("%d ", Vet[i]);
		printf("%d\n", Vet[Tam]);
		Vet.clear();
		printf("In..: ");
		T.InOrd(T.Root);
		for (int i = 0; i < Tam; i++)
			printf("%d ", Vet[i]);
		printf("%d\n", Vet[Tam]);
		Vet.clear();
		printf("Post: ");
		T.PosOrd(T.Root);
		for (int i = 0; i < Tam; i++)
			printf("%d ", Vet[i]);
		printf("%d\n\n", Vet[Tam]);
		Vet.clear();
	}
}