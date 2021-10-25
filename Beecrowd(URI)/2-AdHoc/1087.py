def valid(x, y, xi,  yi, xf, yf):
	return xi + x == xf and yi + y == yf

x = []
y = []
for i in range(8):
	x.append(i + 1)
	y.append(i + 1)
for i in range(8):
	x.append(-1*(i + 1))
	y.append(-1*(i + 1))

while True:
	xi, yi, xf, yf = map(int, input().split())
	if not xi and not yi and not xf and not yf:
		break
	i = 0
	if xi == xf and yi == yf:
		print(0)
		continue
	ok = xi == xf or yi == yf
	while i < 16 and not ok:
		ok = valid(x[i], y[i], xi, yi, xf, yf)
		i += 1
	i = 0
	while i < 8 and not ok:
		ok = valid(x[i], y[i + 8], xi, yi, xf, yf) or valid(x[i + 8], y[i], xi, yi, xf, yf)
		i += 1
	if ok:
		print(1)
	else:
		print(2)