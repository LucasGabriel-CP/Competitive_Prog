while True:
    try:
        N = input().split()
        X = int(N[0])
        Y = int(N[1])
        print(X ^ Y)
    except EOFError:
        break