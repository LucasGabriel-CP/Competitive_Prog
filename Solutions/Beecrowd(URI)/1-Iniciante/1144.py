from sys import stdin

if __name__ == "__main__":
    T = int(stdin.readline())
    for i in range(1, T + 1):
        print(f'{i} {i ** 2} {i * (i ** 2)}')
        print(f'{i} {i ** 2 + 1} {i * (i ** 2) + 1}')