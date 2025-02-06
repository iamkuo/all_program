import random as rd
a = []
for i in range(35):
    a.append(rd.randint(1,100))
print(a)
seat = list(range(35))
sa = []
sseat = []
for i in range(len(a)):
    sa.append(a[i])
    sseat.append(seat[i])
    if i > 0:
        ind = i - 1
        while a[i] > sa[ind]:
            sa[ind+1],sa[ind] = sa[ind],sa[ind+1]
            sseat[ind+1],sseat[ind] = sseat[ind],sseat[ind+1]
            ind -= 1
            if ind < 0:
                break
for i in range(len(a)):
    print(i, sseat[i], sa[i])
