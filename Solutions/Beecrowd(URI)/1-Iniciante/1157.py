from sys import stdin

if __name__ == "__main__":
    T = int(stdin.readline())
    for i in range(1, T + 1):
        if T % i == 0:
            print(i)