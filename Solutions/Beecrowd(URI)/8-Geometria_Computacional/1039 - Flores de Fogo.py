from math import sqrt

def main():
    while True:
        try:
            R1, X1, Y1, R2, X2, Y2 = map(int, input().split())
            Dist = sqrt((X2 - X1) ** 2 + (Y2 - Y1) ** 2) + R2
            if R1 >= Dist:
                print('RICO')
            else:
                print('MORTO')
        except EOFError:
            break

if __name__ == "__main__":
    main()