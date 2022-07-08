def main():
    R, L = map(int, input().split())
    V = (4/3) * (3.1415 * R ** 3)
    print(f'{int(L//V)}')

if __name__ == "__main__":
    main()