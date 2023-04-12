#include<bits/stdc++.h>

template<typename T>
struct Node {
    Node* left = NULL;
    Node* right = NULL;
    T key;
    Node(T val){ key = val; }
};

template<typename T>
struct BinTree{
    Node* root = NULL;
    void insert(Node** R, T val){
        if (!(*R))
            *R = new Node(val);
        else
            if ((*R)->key > val)
                insert(&(*R)->left, val);
            else
                insert(&(*R)->right, val);
    }
    bool busca(Node** R, T val){
        if (!(*R)) return false;
        if ((*R)->key == val) return true;
        if ((*R)->key > val)
            return busca(&(*R)->left, val);
        return busca(&(*R)->right, val);
    }
    bool delAnt(Node **P, T val){
        if (!(*P))
            return false;
        if ((*P)->key > val)
            return delAnt(&(*P)->left, val);
        if ((*P)->key < val)
            return delAnt(&(*P)->right, val);
        if (!(*P)->left){
            (*P) = (*P)->right;
            return true;
        }
        if (!(*P)->right){
            (*P) = (*P)->left;
            return true;
        }

        Node* antecessor = (*P)->left;
        Node* pai = (*P);
        while(antecessor->right){
            pai = antecessor;
            antecessor = antecessor->right;
        }
        if (pai->key != (*P)->key)
            pai->right = antecessor->left;
        else
            pai->left = antecessor->left;
        (*P)->key = antecessor->key;

        return true;
    }
    bool delSuc(Node **P, T val){
        if (!(*P))
            return false;
        if ((*P)->key > val)
            return delSuc(&(*P)->left, val);
        if ((*P)->key < val)
            return delSuc(&(*P)->right, val);
        if (!(*P)->left){
            (*P) = (*P)->right;
            return true;
        }
        if (!(*P)->right){
            (*P) = (*P)->left;
            return true;
        }

        Node* sucessor = (*P)->right;
        Node* pai = (*P);
        while(sucessor->left){
            pai = sucessor;
            sucessor = sucessor->left;
        }
        if (pai->key != (*P)->key)
            pai->left = sucessor->right;
        else
            pai->right = sucessor->right;
        (*P)->key = sucessor->key;

        return true;
    }
    void preOrd(Node* P, std::vector<T> &vet){
        if (P){
            vet.push_back(P->key);
            preOrd(P->left, vet);
            preOrd(P->right, vet);
        }
    }
    void inOrd(Node* P, std::vector<T> &vet){
        if (P){
            inOrd(P->left, vet);
            vet.push_back(P->key);
            inOrd(P->right, vet);
        }
    }
    void posOrd(Node* P, std::vector<T> &vet){
        if (P){
            posOrd(P->left, vet);
            posOrd(P->right, vet);
            vet.push_back(P->key);
        }
    }
};

