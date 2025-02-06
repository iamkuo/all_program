n = int(input('how many line?'))
nmax = -1
lines = list()
for i in range(n):
    perline = input('start end').split()
    perline = [int(perline[i]) for i in range(2)]
    lines.append(perline)
    print(lines)
    if perline[1] > nmax:
        nmax = perline[1]
axie = [0]*(nmax+1)
for i in range(n):
    for j in range(lines[i][0],lines[i][1]+1):
        axie[j] = 1
length = 0
for i in range(nmax):
    if axie[i]+axie[i+1] == 2:
        length += 1
print('Cover length = ',length)
