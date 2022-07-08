from math import sqrt

def main():
    C = int(input())
    for _ in range(C):
        P = int(input())
        G, R, B = 0, 0, 0
        for _ in range(P):
            M, S = input().split()
            if M == 'G':
                G += 1
                if S == 'B':
                    G += 1
            elif M == 'B':
                B += 1
                if S == 'R':
                    B += 1
            elif M == 'R':
                R += 1
                if S == 'G':
                    R += 1
        if G == R and R == B:
            print('trempate')
        elif G > R:
            if G > B:
                print('green')
            elif G == B:
                print('empate')
            else:
                print('blue')
        elif R > G:
            if R > B:
                print('red')
            elif R == B:
                print('empate')
            else:
                print('blue')
        else:
            if B > G:
                print('blue')
            else:
                print('empate')

if __name__ == "__main__":
    main()