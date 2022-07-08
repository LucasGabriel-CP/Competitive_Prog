def main():
    Count = 0
    while True:
        try:
            if Count:
                print()
            FP, FH = map(int, input().split())
            L = int(FP*(5/2) + FH*3)
            Count += 1
            print(f'Molecula #{Count}.:.')
            print(f'Possui {int(2 + L - FP - FH)} atomos e {L} ligacoes')
        except EOFError:
            break

if __name__ == "__main__":
    main()