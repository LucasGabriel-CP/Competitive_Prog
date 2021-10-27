def retNum(cara):
	if cara == 'o' or cara == 'O':
		return '0'
	if cara == 'l':
		return '1'
	if cara <= '9' and cara >= '0':
		return cara
	if cara == '.' or cara == ',' or cara == ' ':
		return ''
	return '-'
	
while True:
	try:
		Str = input()
		Ans = ''
		ok = True
		for i in Str:
			aux = retNum(i)
			if aux == '-':
				ok = False
				break
			Ans += aux
			if (len(Ans) and int(Ans) > 2147483647):
				ok = False
				break
		if not len(Ans) or not ok:
			print('error')
		else:
			print(int(Ans))
		
	except EOFError:
			break