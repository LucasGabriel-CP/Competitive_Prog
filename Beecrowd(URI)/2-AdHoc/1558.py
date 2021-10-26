table = []
for i in range(10005):
	table.append(False)
for i in range(101):
	for j in range(101):
		if i ** 2 + j ** 2 > 10000:
			break
		table[i**2 + j**2] = True
while True:
	try:		
		N = int(input())
		if N < 0:
			print('NO')
			continue
		if table[N] == 1:
			print('YES')
		else: 
			print('NO')
	except EOFError:
		break