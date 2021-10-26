class Node():
    def __init__(self, Val) -> None:
        self.key = Val
        self.left = None
        self.right = None

def insert(R, Val):
    if R is None:
        return Node(Val)
    else:
        if Val < R.key:
            R.left = insert(R.left, Val)
        else:
            R.right = insert(R.right, Val)
    return R

def Search(R, Val):
    if R is None:
        return False
    else:
        if Val == R.key:
            return True
        else:
            if Val < R.key:
                return Search(R.left, Val)
            else:
               return Search(R.right, Val)

def inorder(P, Vet):
    if P is not None:
        inorder(P.left, Vet)
        Vet.append(P.key)
        inorder(P.right, Vet)

def pre(P, Vet):
    if P is not None:
        Vet.append(P.key)
        pre(P.left, Vet)
        pre(P.right, Vet)

def pos(P, Vet):
    if P is not None:
        pos(P.left, Vet)
        pos(P.right, Vet)
        Vet.append(P.key)


Root = None
while True:
    try:
        Vet = list()
        Ent = input().split()
        if len(Ent) > 1:
            if Ent[0] == "I":
                Root = insert(Root, Ent[1])
            else:
                if Search(Root, Ent[1]):
                    print(f'{Ent[1]} existe')
                else:
                    print(f'{Ent[1]} nao existe')
        else:
            if Ent[0] == "INFIXA":
                inorder(Root, Vet)
                for i in range(0, len(Vet) - 1):
                    print(Vet[i], end=" ")
                print(Vet[len(Vet) - 1])
            elif Ent[0] == "PREFIXA":
                pre(Root, Vet)
                for i in range(0, len(Vet) - 1):
                    print(Vet[i], end=" ")
                print(Vet[len(Vet) - 1])
            else:
                pos(Root, Vet)
                for i in range(0, len(Vet) - 1):
                    print(Vet[i], end=" ")
                print(Vet[len(Vet) - 1])
    except EOFError:
        break