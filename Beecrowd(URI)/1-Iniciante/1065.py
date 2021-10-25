count = 0
for i in range(5):
    X = int(input())
    if X % 2 == 0:
        count += 1
print(f'{count} valores pares')