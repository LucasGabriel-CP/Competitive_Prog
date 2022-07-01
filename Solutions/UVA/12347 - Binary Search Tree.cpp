#include <bits/stdc++.h>

using namespace std;
vector<int> vet;

struct Node{
	Node* left = NULL;
	Node* right = NULL;
	int Key;
};

struct Tree{
	Node* Root = NULL;
	void insert(Node* P, Node** R, int Val){
		if (!(*R))
			*R = P;
		else
			if ((*R)->Key > Val)
				insert(P, &(*R)->left, Val);
			else
				insert(P, &(*R)->right, Val);
	}
	void PosOrd(Node* P){
		if (P){
			PosOrd(P->left);
			PosOrd(P->right);
			vet.push_back(P->Key);
		}
	}
};
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int val;
    Tree t;
    Node* No;
    while(cin >> val){
        No = new Node;
        No->Key = val;
        t.insert(No, &t.Root, val);
    }
    t.PosOrd(t.Root);
    for(int i: vet) cout << i << '\n';

    return 0;
}
