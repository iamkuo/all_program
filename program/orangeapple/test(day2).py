'''
dat = int(input())
if dat >= 10 and dat <= 20:
    print('a')
elif dat >= 5 and dat <= 9:
    print('b')
elif dat >= 1 and dat <= 4:
    print('c')
else:
    print('d')
'''
'''
bank =[50000,30000,120000]
for i in range(len(bank)):
    bank[i] += bank[i]/100
print(bank)
'''
'''
John = [90,95,75,80,85]
Mary = [60,75,99,55,90]
Oliver = [80,80,30,95,90]
print(John[1],John[2])
print((Mary[0]+Mary[1]+Mary[2])/3)
print(max(Oliver)-min(Oliver))
'''
'''
now = [4,3,2,1]
while True:
    dat = [int(i)for i in input().split()]
    if len(dat) == 1:
        if dat[0] == 1:
            print(len(now))
        else:
            now.sort()
            print(now)
    else:
        if dat[0] == 2:
            now.append(dat[1])
            print(now)
        else:
            now.pop(now.index(dat[1]))
            print(now)
'''
'''
week = ('Mon','Tue','Wed','Thu','Fri','Sat','Sun')
date = int(input())
day = input()
next_date = int(input())
day = week.index(day)
space = next_date-date
if space%7 == 0:
    print(week[day])
else:
    print(week[(day+space%7)%7])
'''
'''
dat = {'a':0,'b':0,'c':0}
while True:
    which = int(input())
    if which == 1:
        dat['a'] += 1
    elif which == 2:
        dat['b'] += 1
    else:
        dat['c'] += 1
    print(dat)
'''
'''
can = []
for i in range(1,1000+1):
    if i % 11 == 0:
        can.append(i)
print(max(can))

'''
'''
for i in range(1,10):
    for j in range(1,10):
        if i*j < 50:
            print(str(i)+'X'+str(j)+'= '+str(i*j),end=' ')
    print()
'''
'''
while True:
    dat = list(input().lower())
    ans = 0
    match= ['a','e','i','o','u']
    for i in range(len(dat)):
        for j in range(5):
            if dat[i] == match[j]:
                ans += 1
    print(ans)
'''
'''
print([i for i in range(1,input()*3+1)])
'''
'''
dat = [[90,95,75,80,85],
       [60,75,99,55,90],
       [80,80,30,95,90]]
ans = []
for i in range(3):
    ans.append(sum(dat[i])/3)
print(ans)
'''
'''
numbers = [int(i) for i in input().split()]
dat = [int(i) for i in input().split()]
distance = sum(dat[numbers[0]+1:numbers[1]+1])
if distance < numbers[2]:
    print('you died')
else:
    print('hurray! you survived!')
'''
'''
dat = list(range(1,int(input())+1))
for i in dat:
    if i % 7 == 0:
        dat.pop(i)
print(dat)
'''
'''
while True:
    try:
        dat = [int(i) for i in input().split()]
    except:
        break
    dat.pop(0)
    ans = sum(dat)/len(dat)
    if ans > 59:
        print('no')
    else:
        print('yes')
'''
'''
while True:

    try:

        input()

        print(' '.join([str(x) for x in sorted([int(x) for x in input().strip().split()])]))

    except:

        break
'''
times = input()
ans = []
for i in range(times):
    dat = list(input())
    for i in range(len(dat)):
        dat[i] = int(dat[i])
        num = 1
    for i in dat:
        num *= i
    print(num)
