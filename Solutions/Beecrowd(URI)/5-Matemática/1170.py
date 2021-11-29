def main():
    N = int(input())
    for _ in range(N):
        C = float(input())
        count = 0
        while C > 1.000:
            C /= 2
            count += 1
        print(f'{count} dias')
if __name__ == "__main__":
    main()