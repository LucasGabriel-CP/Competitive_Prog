from sys import stdin

if __name__ == "__main__":
    A = int(stdin.readline())
    N = int(stdin.readline())
    Ans = 0
    for i in range(N):
        F = int(stdin.readline())
        if (A * F >= 40000000):
            Ans += 1
    print(Ans)