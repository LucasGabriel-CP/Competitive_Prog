def main():
    from sys import stdin
    N = int(stdin.readline())
    Vet = list(map(int, stdin.readline().split()))
    Visit = [False for r in range(N)]
    Soma = sum(Vet)
    i = 0
    Count = 0
    Casas = 0
    while True:
        if not Visit[i]:
            Visit[i] = 1
            Casas += 1
        if Vet[i] % 2:
            if Vet[i]:
                Count += 1
                Vet[i] -= 1
            i += 1
        else:
            if Vet[i]:
                Count += 1
                Vet[i] -= 1
            i -= 1
        if i < 0 or i == N:
            break

    print(Casas, Soma - Count)

if __name__ == "__main__":
    main()