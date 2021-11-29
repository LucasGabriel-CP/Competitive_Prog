from sys import stdin

if __name__ == "__main__":
    N = int(stdin.readline())
    for i in range(N):
        L = int(stdin.readline())
        Ans = 0
        for j in range(L):
            Str = stdin.readline()
            for k in range(len(Str) - 1):
                Ans += (ord(Str[k]) - 65) + k + j
        print(Ans)