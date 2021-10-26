vetNum = []
for i in range(10):
	vetNum.append(str(i))
	
def Valid(cara):
	if cara in vetNum:
		return False
	return not(cara == '.' or cara == ',')	
	
while True:
	try:
		Frase = input().split()
		numP = 0
		Count = 0
		for Palavra in Frase:
			ok = True
			for i in range(len(Palavra)):
				if i == len(Palavra) - 1 and Palavra[i] == '.':
					Count += len(Palavra)-1
					numP +=1
					ok = False
					break
				if not Valid(Palavra[i]):
					ok = False
					break
			if ok:
				Count += len(Palavra)
				numP += 1
		if not numP:
			print(250)
		elif int(Count/numP) <= 3:
			print(250)
		elif int(Count/numP) <= 5:
			print(500)
		else:
			print(1000)	
		
	except EOFError:
		break