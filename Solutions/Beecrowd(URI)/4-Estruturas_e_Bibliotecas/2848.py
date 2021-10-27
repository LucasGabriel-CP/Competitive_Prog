A = input().split()
N = int(A[0])
Q = int(A[1])
Vet = list()
Num = input().split()
for i in Num:
    Vet.append(int(i))
newVet = list()
for i in range(Q):
    B = input().split()
    L = int(B[0]) - 1
    R = int(B[1])
    K = int(B[2]) - 1
    G = int(B[3])
    D = int(B[4])
    Tot = 0
    newVet = Vet[L:R]
    newVet.sort()
    while L < R:
        if Vet[L] == newVet[K]:
            Tot+=1
        L+=1
    if G > Tot:
        G = G - Tot
    else:
        G = Tot - G
    if D > Tot:
        D = D - Tot
    else:
        D = Tot - D
    Ans = 'G' if G < D else 'D' if G > D else 'E' 
    print(f'{newVet[K]} {Tot} {Ans}')