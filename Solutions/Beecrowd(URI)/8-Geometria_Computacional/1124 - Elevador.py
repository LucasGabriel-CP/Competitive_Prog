from math import sqrt

def main():
    while True:
        L, C, R1, R2 = map(int, input().split())
        if not L and not C and not R1 and not R2:
            break
        P1, P2 = (L - R1, R1), (R2, C - R2)
        Dist = sqrt((P1[0] - P2[0]) ** 2 + (P1[1] - P2[1]) ** 2)
        if max(R1 * 2, R2 * 2) <= min(L, C) and Dist >= R1 + R2:
            print('S')
        else:
            print('N')

if __name__ == "__main__":
    main()