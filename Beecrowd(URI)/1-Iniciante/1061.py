d1 = input().split()
Tempo1 = input().split(':')
H1 = int(Tempo1[0])
M1 = int(Tempo1[1])
S1 = int(Tempo1[2])
d2 = input().split()
Tempo2 = input().split(':')
H2 = int(Tempo2[0])
M2 = int(Tempo2[1])
S2 = int(Tempo2[2])
TotS = S2 - S1
TotM = M2 - M1
TotH = H2 - H1
TotD = int(d2[1]) - int(d1[1])

if TotS < 0:
    TotS += 60
    TotM -= 1
if TotM < 0:
    TotM += 60
    TotH -= 1
if TotH < 0:
    TotH += 24
    TotD -= 1

print(f'{TotD} dia(s)\n{TotH} hora(s)\n{TotM} minuto(s)\n{TotS} segundo(s)')