import random as rd
a = []
for i in range(35):
    a.append(rd.randint(1,100))
print(a)
seat = list(range(35))
for i in range(len(a)):
    for j in range(i+1,len(a)):
        if a[j] > a[i]:
            a[i],a[j] = a[j],a[i]
            seat[i],seat[j] = seat[j],seat[i]
for i in range(len(a)):
    print(i,seat[i],a[i])
