from sys import stdin

if __name__ == "__main__":
    Ans = 0.0
    tam = 0
    Op = stdin.readline()
    for i in range(12):
        for j in range(12):
            N = float(stdin.readline())
            if (i and i <= 5 and j < 5 and j < i):
                Ans += N 
                tam += 1
            elif (i and i > 5 and j + i <= 10):
                Ans += N
                tam += 1
    if Op[0] == 'S':
        print(f'{Ans}')
    else:
        print(f'{round(Ans/tam, 1)}')