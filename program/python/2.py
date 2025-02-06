num = int(input('enter a number(<65535):'))
lis = []
while num/2 != 0:
    lis.append(num%2)
    num//=2
lis.reverse()
print(lis)
for i in range(16-len(lis)):
    lis.insert(0,0)
print(lis)
