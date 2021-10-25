import math

def isPrime(n) ->bool:
    if n < 5 or n % 2 == 0 or n % 3 == 0:
        return n == 2 or n == 3
    i = 5
    k = math.sqrt(n) + float(1e-9)
    while i <= k:
        if n % i == 0 or n % (i + 2) == 0:
            return False
        i += 6
    return True


Primos = []
for i in range(35000):
    if i > 1 and isPrime(i):
        Primos.append(i)

while True:
    try:
        N = int(input())
        if N == 0:
            break
        if N == 1:
            print(1)
            continue
        X = list()
        for i in range(N + 1):
            if i > 0:
                X.append(i)
        PPosi = 0
        At = Primos[PPosi] - 1
        while N > 1:
            i = At
            X.pop(i)
            PPosi += 1
            N -= 1
            At = (At + Primos[PPosi] - 1) % N
        print(X[At])
    except EOFError:
        break