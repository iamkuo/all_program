#dat = [int(num) for num in input('enter score and requirements').split()]
'''
for i in range(2,31,2):
    print(i,end = '')
    print(' ',end = '')
print()
for i in range(10,-1,-1):
    print(i,end = '')
    print(' ',end = '')
print()
tmp = 2
for i in range(9):
    print(tmp,end = '')
    print(' ',end = '')
    tmp *= 2
print()
tmp = 3
for i in range(7):
    print(tmp,end = '')
    print(' ',end = '')
    tmp *= 3
print()
for i in range(-100,81,10):
    print(i,end = '')
    print(' ',end = '')
print()
tmp = 128
for i in range(8):
    print(int(tmp),end = '')
    print(' ',end = '')
    tmp /= 2
'''
'''
n = int(input())
i = 1
while i <= n :
    if n%i == 0:
        print(i,end = ' ')
    i = i + 1
'''
'''
for i in range(1,10):
    for j in range(1,10):
        if i*j >= 10:
            if i*j == 81:
                print(str(i)+'X'+str(j)+'='+str(i*j))
            else:
                print(str(i)+'X'+str(j)+'='+str(i*j),end=' ')
        else:
            print(str(i)+'X'+str(j)+'= '+str(i*j),end=' ')
    print()
'''
'''
w = int(input())
h = int(input())
for i in range(h):
    print('*'*w)
'''
'''
for i in range(1,6):
    print(' '*(5-i)+'*'*i)
'''
'''
for i in range(1,6):
    print('*'*i)
'''
'''
for i in range(1,6):
    print(' '*(5-i)+'* '*i)
for i in range(4,-1,-1):
    print(' '*(5-i)+'* '*i)
'''
'''
for i in range(6):
    for j in range(i):
        print(j%2,end = '')
    print()
'''
'''
for i in range(1,6):
    for j in range(1,6):
        if j == i:
            print(0,end = '')
        else:
            print(i,end = '')
    print()
'''
'''
ax = '-1'
ay = '3.14'
bx = '5'
by = '0.33'
a1 = True
a2 = False
a3 = False
a4 = False
if a1:
    print(1)
elif a2:
    print(2)
elif a3:
    print(3)

else:
    print(4)
b1 = False
b2 = True
b3 = False
b4 = False
if b1:
    print(1)
elif b2:
    print(2)
elif b3:
    print(3)
else:
    print(4)
'''

for i in range(5,0,-1):
    print(' '*(5-i)+'*'*i)
