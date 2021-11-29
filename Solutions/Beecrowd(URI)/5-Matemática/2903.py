from math import gcd
from sys import stdin

if __name__ == "__main__":
    N,M = map(int, stdin.readline().split('.'))
    N = int(N * 100 + M)
    print(f'{36000//gcd(N, 36000)}')