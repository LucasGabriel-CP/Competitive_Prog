from sys import stdin

if __name__ == "__main__":
    while True:
        try:
            N, M = map(int, stdin.readline().split())
            print(abs(N - M))
        except:
            break