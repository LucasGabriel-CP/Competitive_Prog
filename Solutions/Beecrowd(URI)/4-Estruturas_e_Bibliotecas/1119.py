def solve(vet, N, k, m):
    Ans = ''
    l = r = 0
    while N > 1:
        l = (l + k) % N
        for i in range(m):
            r = (r - 1)
            if r < 0:
                r = N - 1
        
        a = vet[l]
        b = vet[r]
        if (a < 10):
            Ans += '  '
        elif a < 100:
            Ans += ' '
        Ans += str(a)
        vet.remove(a)
        N -= 1
        if a != b:
            N -= 1
            if (b < 10):
                Ans += '  '
            elif b < 100:
                Ans += ' '
            Ans += str(b)
            vet.remove(b)
        if not N:
            break
        Ans += ','
        if a > b:
            l -= 1
        elif b > a:
            r -= 1

    if N:
        a = vet[N - 1]
        if (a < 10):
            Ans += '  '
        elif a < 100:
            Ans += ' '
        Ans += str(a)
    print(Ans)

while True:
    N, k, m = map(int, input().split())
    if not N and not m and not k:
        break
    vet = [i for i in range(1, N + 1)]
    solve(vet, N, k - 1, m)