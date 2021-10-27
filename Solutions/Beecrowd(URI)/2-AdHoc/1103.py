while True:
	Hi, Mi, Hf, Mf = map(int, input().split())
	if not Hi and not Mi and not Hf and not Mf:
		break
	if Hi > Hf or Hi == Hf and Mi > Mf:
		Hf += 24
	pi = Hi * 60 + Mi
	pf = Hf * 60 + Mf
	print(pf - pi)