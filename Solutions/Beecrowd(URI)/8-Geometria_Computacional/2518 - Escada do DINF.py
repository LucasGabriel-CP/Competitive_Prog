from math import sqrt

def main():
    while True:
        try:
            N = int(input())
            H, C, L = map(int, input().split())
            D = sqrt(H * H + C * C)
            print(f'{(L/100 * D/100 * N):.4f}')
        except EOFError:
            break

if __name__ == "__main__":
    main()