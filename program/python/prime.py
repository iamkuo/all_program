number = int(input("enter a number"))
prime1 = list(range(2, number+1))
print(prime1)
prime2 = []
primeAns = []
for i in range(2, number+1):
    prime2.append(0)
for j in range(0, number-2):
    for k in range(j+1, len(prime1)):
        if prime2[k] == 0:
            if int(prime1[k]) % int(prime1[j]) == 0:
                prime2[k] = 1
i  = 0
for i in range(len(prime1)):
    if prime2[i] == 0:
        primeAns.append(prime1[i])
print(primeAns)

