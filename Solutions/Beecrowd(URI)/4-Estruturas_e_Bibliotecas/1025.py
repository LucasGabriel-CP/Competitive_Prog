def MergeSort(A):
    if len(A) > 1:
        M = len(A) // 2
        L = A[M:]
        R = A[:M]

        MergeSort(L)
        MergeSort(R)

        i = j = k = 0
        while i < len(L) and j < len(R):
            if L[i] <= R[j]:
                A[k] = L[i]
                i += 1
            else:
                A[k] = R[j]
                j += 1
            k += 1
        while i < len(L):
            A[k] = L[i]
            i += 1
            k += 1
 
        while j < len(R):
            A[k] = R[j]
            j += 1
            k += 1

def binSearch(Vet, k) -> int:
    pi = 0
    pf = len(Vet) - 1
    while pi < pf:
        Meio = (pf + pi) // 2
        if k > Vet[Meio]:
            pi = Meio + 1
        else:
            pf = Meio
    return pi

Count = 1
while True:
    try:
        A = input().split()
        N = int(A[0])
        Q = int(A[1])
        if not N:
            break

        Vet = []
        for i in range(N):
            k = int(input())
            Vet.append(k)
        MergeSort(Vet)
        
        print(f'CASE# {Count}:')
        for i in range(Q):
            k = int(input())
            Posi = binSearch(Vet, k)
            if Vet[Posi] == k:
                print(f'{k} found at {Posi + 1}')
            else:
                print(f'{k} not found')
        Count += 1

    except EOFError:
        break