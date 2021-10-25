count = 0
X = int(input())
if X % 2 == 0:
    X += 1
while count < 6:
    if X % 2 != 0:
        print(X)
    X += 2
    count += 1